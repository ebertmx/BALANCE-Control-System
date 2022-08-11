classdef BALANCEControlSystem <handle %#codegen
    properties (Access = public)
        cam, rpi, DIRpin, PWMpin;
        ballPixel, ballPoint, ballPosition, ballObjectivePosition;
        beamPixels, beamPoints,beamAngle;
        CenterReferencePixels, CenterReferencePoint, ballRadius;

        rawFrame, bimgLOW, bimgHIGH;
        lowThresh = 0.6;
        highThresh = 0.9;

        ballDetectionRadiusRange = [20,40];

        beamSearchRange = 50;
        ballSearchRange = 150;

        Z = 0.380;
        LED_HYPO = 0.24309; %m
        LED_lineoffset = 9.85/1000; %m
        LED_refoffset = 8.3/1000 ; %m

        px = 625.21687001741327;
        py = 623.78140876507746;
        u0 = 319.96647337485342;
        v0 = 243.30511332809766;

        positionError = zeros(1,2);
        thetaError = zeros(1,2);
        bKp = 0.2105;
        bKi = 0.05;
        bKd = 0.4771;
        bKa = 0.08;
        alphaFilter = 0.1164;
        bKc = 1;

        P_err = zeros(1,2);
        I_err = zeros(1,2);
        D_err = zeros(1,2);
        A_err = zeros(1,2);
        Dfilter_err = zeros(1,2);


        thetaSignal = 0;
        maxBeamAngle = 0.2;
        minBeamAngle = -0.2;

        %         mKp = 26.4845;
        %         mKi = 22.29875*0;
        %         mKd = 7.31174;
        mKp = 4.125;
        mKi = 0.0038528*(0);
        mKd = 0.27;

        mKc = 1;
        alphaFilter_sig = 0.01;

        P_sig = zeros(1,2);
        I_sig = zeros(1,2);
        D_sig = zeros(1,2);
        Dfilter_sig = zeros(1,2);


        actuatorControlSignal = 0, motorDuty, motorDir;
        maxABSMotorSig= 0.9
        minABSMotorSig = 0.08

        thetaclockSig = tic;
        controlclockSig = tic;

        angleOffset = 0.005;

    end

    methods
        %         function delete(~)
        %         end
        function obj = BALANCEControlSystem (setrpi, setPWMpin, setDIRpin)
            %% Pre Initialization %%
            % Any code not using output argument (obj)
            if(isempty(setrpi) || isempty(setDIRpin)||isempty(setPWMpin))
                disp("need rpi and pin")
                %                 delete()
            else
                obj.rpi = setrpi;
                obj.DIRpin = setDIRpin;
                obj.PWMpin = setPWMpin;
            end
            obj.ballObjectivePosition = [0;0];
        end

        %% Configure Hardware %%

        function status = SetUpHardware(obj)
            if(obj.ConfigureMotor() && obj.ConfigureCamera())
                status = true;
            else
                status = false;
            end
        end
        %configure the motor
        function status = ConfigureMotor(obj)
            %set PWM pin and frequency
            configurePin(obj.rpi, obj.PWMpin, 'PWM');
            writePWMDutyCycle(obj.rpi, obj.PWMpin, 0.0);
            writePWMFrequency(obj.rpi, obj.PWMpin, 8000);

            %set direction pin
            configurePin(obj.rpi,obj.DIRpin, 'DigitalOutput');
            writeDigitalPin(obj.rpi,obj.DIRpin,1);

            status = true;
        end

        %configure the camera
        function status = ConfigureCamera(obj)
            obj.cam = cameraboard(obj.rpi,'Resolution','640x480');
            for i = 1:10
                I = snapshot(obj.cam);
            end
            if( isempty(I))
                status = false;
            else
                status = true;
            end
        end

        %% Image collection, processing, object detection, and VS %%

        %Get and process images from the camera
        function status = GrabFrames(obj)
            obj.rawFrame = snapshot(obj.cam);
            if(~isempty(obj.rawFrame))
                img = rgb2gray(obj.rawFrame);
                img = imgaussfilt(img,2);
                %threshhold the gray scale image to isolate the ball
                obj.bimgLOW = imbinarize(img,obj.lowThresh);
                obj.bimgHIGH = imbinarize(img,obj.highThresh);
                status = true;
            else
                status = false;
            end
        end

        %Find calibration points in image plane
        function status = CalibrateImage(obj)
            cy1 = 220;
            cy2 = 280;
            cx1 = 280;
            cx2 = 360;
            obj.GrabFrames();
            if(~isempty(obj.bimgHIGH))

                simg = obj.bimgHIGH(cy1:cy2,cx1:cx2);
                sc  = regionprops(simg, 'Centroid','Area');

                if (~isempty(sc))
                    scdata = struct2table(sc);
                    id = find(scdata.Area < 100 & scdata.Area>30);
                    if(~isempty(id))
                        center = scdata.Centroid(id(1),:);
                    else
                        status = false;
                        return;
                    end
                end
                obj.CenterReferencePixels = [center(1)+(cx1-1), center(2)+(cy1-1)];
                obj.CenterReferencePoint = obj.pixel2point(obj.CenterReferencePixels());
                status = true;
                return;
            end
            status = false;
        end


        %find feature which dictate ball position and beam angle
        function [statusball, statusbeam] = LocateFeatures(obj)
            %             statusball = false;
            statusbeam = false;
            if(obj.GrabFrames())
                if(~isempty(obj.ballPixel()))
                    ballx1 =  min(max(uint32(obj.ballPixel(1) - obj.ballSearchRange),1),640);
                    ballx2 = min(max(uint32(obj.ballPixel(1)  + obj.ballSearchRange),1),640);
                    bally1 =min(max(uint32(obj.ballPixel(2)  - obj.ballSearchRange),1),480);
                    bally2 =min(max(uint32(obj.ballPixel(2) + obj.ballSearchRange),1),480);
                    searchimage = obj.bimgLOW(bally1:bally2,ballx1:ballx2);
                else
                    ballx1 = 0;
                    bally1 = 0;
                    searchimage = obj.bimgLOW;
                end
                [centers, radii] = imfindcircles(searchimage,obj.ballDetectionRadiusRange, ...
                    'ObjectPolarity','bright');

                if(size(centers,2)>=1)
                    obj.ballPixel(1,1) = centers(1,1)+ballx1;
                    obj.ballPixel(1,2) = centers(1,2) +bally1;
                    obj.ballRadius = radii(1);
                    statusball = true;
                else
                    statusball=false;
                    return;
                end

                %                 right = obj.bimgH(1:480,540:640);
                %%limit the range around the previous position
                if(~isempty(obj.beamPoints()))
                    beamx1 = min(max(uint32(obj.beamPixels(1)-obj.beamSearchRange),1),640);
                    beamx2 = min(max(uint32(obj.beamPixels(1) +obj.beamSearchRange),1),640);
                    beamy1 =min(max(uint32(obj.beamPixels(2) - obj.beamSearchRange),1),480);
                    beamy2 =min(max(uint32(obj.beamPixels(2) + obj.beamSearchRange),1),480);
                    left = obj.bimgHIGH (beamy1:beamy2, beamx1:beamx2);

                else
                    beamx1 = 0;
                    beamy1 = 0;
                    left = obj.bimgHIGH(1:480,1:100);
                end
                %
                %                 rs  = regionprops(right, 'Centroid');
                ls  = regionprops(left, 'Centroid', 'Area');
                if (~isempty(ls))
                    %                     obj.beamPoints(1,:) = rs.Centroid;
                    %                     obj.beamPoints(1,1) = obj.beamPoints(1,1)+539;
                    lsdata = struct2table(ls);
                    idb = find(lsdata.Area < 80 & lsdata.Area>10);
                    if(~isempty(idb))
                        centroidLED = lsdata.Centroid(idb(1),:);
                    else
                        statusbeam = false;
                        return;
                    end

                    obj.beamPixels(1,1) =centroidLED(1) + beamx1-1;
                    obj.beamPixels(1,2) =centroidLED(2) + beamy1-1;
                    obj.beamPoints(1,:) = obj.pixel2point(obj.beamPixels(1,:));
                    %lcent = ls.Centroid;
                    %Calculate the angle
                    ytemp = (obj.beamPoints(1,2) - (obj.LED_lineoffset)) - obj.CenterReferencePoint(1,2);
                    xtemp = -1 * (obj.beamPoints(1,1)-obj.CenterReferencePoint(1,1));
                    obj.beamAngle = obj.angleOffset + atan2(ytemp, xtemp);
                    %                     obj.beamAngle = pi/2 +obj.angleOffset + atan2( (obj.beamPoints(2,1)-obj.beamPoints(1,1)), ...
                    %                         (obj.beamPoints(2,2)-obj.beamPoints(1,2))) ;
                    statusbeam = true;
                    return;
                end


            end
            statusbeam = false;
            statusball = false;
        end

        %% Control Systems %%
        %set the objective position to the center of the beam
        function  SetObjective(obj)
            if(isempty(obj.CenterReferencePixels))
                obj.CalibrateImage()
                if(isempty(obj.CenterReferencePixels))
                    disp("Can't Find Reference Point");
                    return;
                end
            end
            obj.CenterReferencePoint(1) = (obj.CenterReferencePixels(1) - obj.u0)/obj.px *obj.Z;
            obj.CenterReferencePoint(2) = ((obj.CenterReferencePixels(2)) - obj.v0)/obj.py *obj.Z;
            obj.ballObjectivePosition(1) = obj.CenterReferencePoint(1);
            obj.ballObjectivePosition(2) = obj.CenterReferencePoint(1) +7;
        end

        %Calculate the distance along the beam from the ball to the
        %target position
        function CalcPositionError(obj)
            if(~isempty(obj.ballPixel()))
                obj.ballPoint(1,:) = obj.pixel2point(obj.ballPixel(1,:));
                obj.positionError(1)= sign(obj.ballPoint(1)-obj.ballObjectivePosition(1))...
                    *sqrt((obj.ballObjectivePosition(1)-obj.ballPoint(1))^2 ...
                    + (obj.ballPoint(2) -obj.ballPoint(2))^2);

                if (abs(obj.positionError(1)) < 1e-4)
                    obj.positionError(1) = 0;
                end
            end
        end

        %Calculate the desired beam angle and find the difference with the
        %current beam angle
        function CalcThetaError(obj)
            dT = toc(obj.thetaclockSig);
            %a = 0.5;
            %obj.positionError(1) = obj.positionError(1) + a*dT*obj.D_err(1) + a*dT^2*(obj.A_err(1)/2);
            %Calculate PID errors
            %Proportional
            obj.P_err(1) =(obj.positionError(1));%; + 0.5*(obj.positionError(1))^2;


            %Integral
            %implement clamping
            if (obj.thetaSignal < obj.maxBeamAngle)  && (obj.thetaSignal > obj.minBeamAngle)

                obj.I_err(1) = (obj.I_err(2) + dT*obj.positionError(1));

            end
            %Differential
            obj.Dfilter_err(1) = obj.alphaFilter * obj.positionError(1) + (1-obj.alphaFilter)*obj.Dfilter_err(2);

            obj.D_err(1) = (obj.Dfilter_err(1) - obj.Dfilter_err(2))/dT ;

            %Acceleration
            obj.A_err(1) = (1-2*obj.positionError(1))*(obj.D_err(1) - obj.D_err(2))/dT;

            %Signal
            obj.thetaSignal = obj.bKc * (obj.bKp * obj.P_err(1) + obj.bKi * obj.I_err(1) ...
                + obj.bKd * obj.D_err(1) + obj.bKa * obj.A_err(1));

            %Apply beam angle limits
            if obj.minBeamAngle > obj.thetaSignal
                obj.thetaSignal = obj.minBeamAngle;

            elseif obj.maxBeamAngle < obj.thetaSignal
                obj.thetaSignal = obj.maxBeamAngle;

            end

            %Assign Error values
            obj.thetaError(1) =obj.thetaSignal -  obj.beamAngle;
            if (abs(obj.thetaError(1))<5e-3)
                obj.thetaError(1) = 0;
            end


            %Update Previous Values
            obj.P_err(2) = obj.P_err(1);
            obj.I_err(2) = obj.I_err(1);
            obj.Dfilter_err(2) = obj.Dfilter_err(1);
            obj.D_err(2) = obj.D_err(1);
            obj.positionError(2) = obj.positionError(1);

            obj.thetaclockSig = tic;
        end

        %Generate the motor signal based on the desired beam angle
        function CalcMotorSignal(obj)
            dT = toc(obj.controlclockSig);

            %%obj.thetaError(1) = obj.thetaError(1) + dT*obj.D_sig(1);
            %Proportional
            obj.P_sig(1) = obj.thetaError(1);

            %Integral
            %implement clamping
            if (abs(obj.actuatorControlSignal(1))< obj.maxABSMotorSig  &&  abs(obj.actuatorControlSignal(1))> obj.minABSMotorSig)

                obj.I_sig(1) = (obj.I_sig(2) + dT * obj.thetaError(1));
            end
            %Differential
            obj.Dfilter_sig(1) = obj.alphaFilter_sig * obj.thetaError(1) + (1 - obj.alphaFilter_sig) * obj.Dfilter_sig(2);
            obj.D_sig(1) = (obj.Dfilter_sig(1) - obj.Dfilter_sig(2))/dT;

            %Signal
            obj.actuatorControlSignal(1) = obj.mKc * (obj.mKp * obj.P_sig(1) + obj.mKi * obj.I_sig(1) + obj.mKd * obj.D_sig(1));


            if (obj.minABSMotorSig > abs(obj.actuatorControlSignal(1)) &&  abs(obj.actuatorControlSignal(1))>0.009)
                obj.actuatorControlSignal(1) = sign(obj.actuatorControlSignal(1))*obj.minABSMotorSig;

            elseif obj.maxABSMotorSig < abs(obj.actuatorControlSignal(1))
                obj.actuatorControlSignal(1) = sign(obj.actuatorControlSignal(1))*obj.maxABSMotorSig;

            elseif abs(obj.actuatorControlSignal(1))<0.009
                obj.actuatorControlSignal(1) = 0;
            end

            obj.P_sig(2) = obj.P_sig(1);
            obj.I_sig(2) = obj.I_sig(1);
            obj.Dfilter_sig(2) = obj.Dfilter_sig(1);
            obj.D_sig(2) = obj.D_sig(1);
            obj.actuatorControlSignal(2) = obj.actuatorControlSignal(1);

            obj.thetaError(2) = obj.thetaError(1);
            obj.controlclockSig = tic;
        end


        %Actuate the motor with the generated motor signal
        function ControlMotor(obj)
            obj.motorDuty = abs(obj.actuatorControlSignal(1));
            if sign(obj.actuatorControlSignal(1))>0
                obj.motorDir =1;
            else
                obj.motorDir = 0;
            end

            writeDigitalPin(obj.rpi, obj.DIRpin, obj.motorDir);
            writePWMDutyCycle(obj.rpi, obj.PWMpin, obj.motorDuty);

        end
        %Run the motor for a specific period of time in a direction and at
        %a speed.


        function RunMotorFor(obj,dir,speed, time)
            temp = tic;
            while toc(temp)<time
                writeDigitalPin(obj.rpi, obj.DIRpin, dir);
                writePWMDutyCycle(obj.rpi, obj.PWMpin, speed);
            end
            writePWMDutyCycle(obj.rpi, obj.PWMpin, 0);
        end

        function RunMotor(obj,dir,speed)
            writeDigitalPin(obj.rpi, obj.DIRpin, dir);
            writePWMDutyCycle(obj.rpi, obj.PWMpin, speed);
        end

        %stop the motor
        function StopMotor(obj)
            writePWMDutyCycle(obj.rpi, obj.PWMpin, 0);
        end


        function RunToAngle(obj, angle,speed)
            obj.LocateFeatures
            if (angle -obj.beamAngle)>0
                dir = 0;
            else
                dir =1;
            end
            while abs(obj.beamAngle()-angle)>0.05
                RunMotor(dir,speed)
            end
            obj.StopMotor();
        end

        function SetGains (obj,setKp, setKi,setKd)
            obj.bKp = setKp;
            obj.bKi = setKi;
            obj.bKd = setKd;
        end


        %
        %         function ShowImage(obj)
        %             imshow(obj.bimgLOW)
        %             hold on
        %             plot(obj.u0,obj.v0, 'b*');
        %             plot(obj.CenterReferencePixels(1),obj.CenterReferencePixels(2),'r*')
        %             viscircles(obj.ballPixel,26);
        %             viscircles(obj.beamPixels, 5);
        %             hold off
        %         end


        function meter = pixel2point(obj, pixel)
            meter = zeros(1,2);
            meter(1) = (pixel(1) - obj.u0)/obj.px * obj.Z;
            meter(2) = (pixel(2) - obj.v0)/obj.py * obj.Z;

        end

        function DelayPID(obj)

            obj.controlclockSig = tic;
            obj.thetaclockSig = tic;

        end
    end

end
