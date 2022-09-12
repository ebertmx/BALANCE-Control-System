function TUNEBALANCEController2() %#codegen
bKp = 0.2105;
bKi = 0.01;
bKd = 0.4771;
bKa = 0.48;
alphaFilter = 0.1164;

fig= uifigure;
hold on;
P = uislider(fig, 'Position',[50 700 500 3]);
P.Value = bKp;
P.Limits = [0.15,0.26];

I = uislider(fig, 'Position',[50 400 500 3]);
I.Value = bKi;
I.Limits = [0.007,0.09];

D = uislider(fig, 'Position',[50 300 500 3]);
D.Value = bKd;
D.Limits = [0.35,0.8];


A = uislider(fig, 'Position',[50 200 500 3]);
A.Value = bKa;
A.Limits = [0.01,0.5];

filt = uislider(fig, 'Position',[50 100 500 3]);
filt.Value = alphaFilter;
filt.Limits = [0.01,0.5];

cycles = 10000;
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
    
    %Update
    Controller.bKp = P.Value;
    Controller.bKi = I.Value;
    Controller.bKd = D.Value;
    Controller.alphaFilter = filt.Value;

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