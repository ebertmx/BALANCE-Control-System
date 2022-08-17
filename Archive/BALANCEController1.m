function BALANCEController1() %#codegen

%clear;
close all;

cycles = 500;
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
end

Controller.StopMotor();

end