function TUNEBALANCEController2() %#codegen

cycles = 1000;
rpi = raspi();
PWMpin = 13;
DIRpin = 6;

pause(0.001);

%create Balancesystem controller and set it up
Controller = BALANCEControlSystem(rpi,PWMpin,DIRpin);
Controller.SetUpHardware();

while(~Controller.CalibrateImage())
    disp("Calibrating");
    %     imshow(Controller.bimgLOW);
    pause(0.001)
end
Controller.LocateFeatures();
Controller.SetObjective();


positionError = zeros(cycles,1);
thetaError = zeros(cycles,1);
beamAngle = zeros(cycles,1);
motorSignal = zeros(cycles,1);
PIDsig = zeros(cycles,3);
PIDerr = zeros(cycles,4);
ballPixels = zeros(cycles,2);
beamPixels = zeros(cycles,2);
sampletime = zeros(cycles,1);



%Initialize PID
for i=1:15
    [statusball, statusbeam] = Controller.LocateFeatures();
    if(statusball && statusbeam)
        Controller.CalcPositionError();
        Controller.CalcThetaError();
        Controller.CalcMotorSignal();
    end
end

Controller.I_err = [0,0];
Controller.I_sig = [0,0];

for i=1:cycles
   t = tic;
    [statusball, statusbeam] = Controller.LocateFeatures();
    if(statusball && statusbeam)
        Controller.CalcPositionError();
        Controller.CalcThetaError();
        Controller.CalcMotorSignal();

        Controller.ControlMotor();

    elseif (~statusball)
        disp("Cant find Ball")
        Controller.StopMotor();
        Controller.DelayPID();
    elseif (~statusbeam)
        disp("Cant find Beam")
        Controller.StopMotor();
        Controller.DelayPID();
    end
    pause(0.0001)

    PIDsig(i,1) = Controller.P_sig(1);
    PIDsig(i,2) = Controller.I_sig(1);
    PIDsig(i,3) = Controller.D_sig(1);

    PIDerr(i,1) = Controller.bKp* Controller.P_err(1);
    PIDerr(i,2) = Controller.bKi* Controller.I_err(1);
    PIDerr(i,3) = Controller.bKd* Controller.D_err(1);
    PIDerr(i,4) = Controller.bKa* Controller.A_err(1);

    positionError(i) = Controller.positionError(1);
    thetaError(i) = Controller.thetaError(1);
    beamAngle(i) = Controller.beamAngle;
    motorSignal(i) = Controller.actuatorControlSignal(1);
    ballPixels(i,:) = Controller.ballPixel;
    beamPixels(i,:) = Controller.beamPixels;
    sampletime(i) = toc(t);
    
    %control frames per second
    while(toc<(1/20))
    continue;
    
    end
end

Controller.StopMotor();

end