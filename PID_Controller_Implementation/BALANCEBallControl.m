function BALANCEBallControl()

clear;
close all;
rpi = raspi();
PWMpin = 13;
DIRpin = 6;

pause(0.001);

%create Balancesystem controller and set it up
Controller = BALANCEControlSystem(rpi,PWMpin,DIRpin);
Controller.SetUpHardware();

while(~Controller.CalibrateImage())
    disp("Calibrating");
    imshow(Controller.bimgLOW);
    pause(0.001)
end
Controller.LocateFeatures();
Controller.SetObjective();
pause(0.01);

pause(0.01);

cycles = 200;
% positionplot = zeros(cycles,1);
% thetaplot = zeros(cycles,1);
% angleplot = zeros(cycles,1);
% motorplot = zeros(cycles,1);
% PIDsigplot = zeros(cycles,3);
% PIDerr = zeros(cycles,4);

% figure
% hold on
set(gcf,'CurrentCharacter','@');
pause(1);


for i=1:50
    [statusball, statusbeam] = Controller.LocateFeatures();
    %Controller.ShowImage();
    if(statusball && statusbeam)
        Controller.CalcPositionError();
        Controller.CalcThetaError();
        Controller.CalcMotorSignal();
    end
end

Controller.I_err = [0,0];
Controller.I_sig = [0,0];

for i=1:cycles

    fpsc = tic;
    %     Controller.SetGains(P.Value,I.Value,D.Value);
    [statusball, statusbeam] = Controller.LocateFeatures();

    %     Controller.ShowImage();
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

    fps =1/toc(fpsc)


    k=get(gcf,'CurrentCharacter');
    if k~='@'
        Controller.StopMotor();
        break;
    end

    pause(0.0001)

%     PIDsigplot(i,1) = Controller.P_sig(1);
%     PIDsigplot(i,2) = Controller.I_sig(1);
%     PIDsigplot(i,3) = Controller.D_sig(1);
% 
%     PIDerr(i,1) = Controller.bKp* Controller.P_err(1);
%     PIDerr(i,2) = Controller.bKi* Controller.I_err(1);
%     PIDerr(i,3) = Controller.bKd* Controller.D_err(1);
%     PIDerr(i,4) = Controller.bKa* Controller.A_err(1);
% 
%     positionplot(i) = Controller.positionError(1);
%     thetaplot(i) = Controller.thetaError(1);
%     angleplot(i) = Controller.beamAngle;
%     motorplot(i) = Controller.actuatorControlSignal(1);



    %         total_t = toc(fpsc);
end

Controller.StopMotor();

% subplot(2,2,1)
% hold on
% plot(positionplot, 'k-');
% plot(thetaplot,'r-');
% plot(angleplot, 'c-');
% plot(motorplot,'b-');
% hold off
% 
% subplot(2,2,2)
% hold on
% plot(PIDerr(:,1), 'k-');
% plot(PIDerr(:,2), 'r-');
% plot(PIDerr(:,3), 'c-');
% plot(PIDerr(:,4), 'b-');
% hold off
% subplot(2,2,3);
% hold on
% plot(PIDsigplot(1:i,1), 'r-');
% plot(PIDsigplot(1:i,2), 'c-');
% plot(PIDsigplot(1:i,3), 'b-');
% hold off

close all;
clear fig
end