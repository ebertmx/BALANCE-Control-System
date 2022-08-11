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
for i=1:50
    Controller.LocateFeatures();
Controller.CalcPositionError();
Controller.CalcThetaError();
Controller.CalcMotorSignal();
end
pause(0.01);

cycles = 100;
positionplot = zeros(cycles,1);
thetaplot = zeros(cycles,1);
angleplot = zeros(cycles,1);
motorplot = zeros(cycles,1);
PIDsigplot = zeros(cycles,3);
 PIDerr = zeros(cycles,3);

figure
hold on
set(gcf,'CurrentCharacter','@');
pause(1);

for i=1:cycles

    fpsc = tic;
    %     Controller.SetGains(P.Value,I.Value,D.Value);
    status = Controller.LocateFeatures();
%     Controller.ShowImage();
    if(status)
        Controller.thetaError(1) = 0 - Controller.beamAngle;
        Controller.CalcMotorSignal();
         Controller.ControlMotor();
    else
        disp("Cant find Ball or Beam")
        Controller.StopMotor();
       Controller.StopMotor();
        Controller.DelayPID();
        %Controller.ShowImage();
    end

    fps =1/toc(fpsc);
    disp(fps)

    k=get(gcf,'CurrentCharacter');
    if k~='@'
        Controller.StopMotor();
        break;
    end

    pause(0.0001)
        PIDsigplot(i,1) = Controller.mKp*Controller.P_sig(1);
        PIDsigplot(i,2) = Controller.mKi*Controller.I_sig(1);
        PIDsigplot(i,3) = Controller.mKd*Controller.D_sig(1);
    
        PIDerr(i,1) = Controller.bKp* Controller.P_err(1);
        PIDerr(i,2) = Controller.bKi* Controller.I_err(1);
        PIDerr(i,3) = Controller.bKd* Controller.D_err(1);
    positionplot(i) = Controller.positionError(1);
    thetaplot(i) = Controller.thetaError(1);
    angleplot(i) = Controller.beamAngle;
    motorplot(i) = Controller.actuatorControlSignal(1);
    %plot(positionplot(1:i),'k-');

%    plot(thetaplot(1:i),'y-');
%     plot(PIDerr(1:i,1), 'r-');
%     plot(PIDerr(1:i,2), 'b-');
%     plot(PIDerr(1:i,3), 'g-');
        plot(motorplot(1:i), 'y-');
        plot(PIDsigplot(1:i,1), 'r-');
        plot(PIDsigplot(1:i,2), 'g-');
        plot(PIDsigplot(1:i,3), 'b-');

    plot(angleplot(1:i), 'k-');
    %     plot(PIDsigplot(1:i,1), 'y-')

    %         total_t = toc(fpsc);
end

Controller.StopMotor();

%  figure;
%  hold on
% plot(positionplot, 'b-')
% plot(thetaplot,'g-')
% plot(angleplot, 'r-');
% plot(motorplot,'o-')
% hold off
close all;
clear fig
end