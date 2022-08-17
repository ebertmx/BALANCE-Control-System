%% About BALANCE Control System
%Matthew Ebert
%ebertmx@gmail.com

% Created
% 2022-AUG-16
% For
% University of Vicotria ECE 490
% Visual Servoing and Computer Vision Control Systems
% Supervisor: Dr Capson


%% Description 
% This program runs the BALANCE system using the BALANCE controller class

function MAIN_BALANCEController() %#codegen
%% Define Parameters and Plot Arrays

cycles = 1000;%number of frames to run system
%Raspberry Pi
rpi = raspi();
PWMpin = 13;
DIRpin = 6;

positionError = zeros(cycles,1);
thetaError = zeros(cycles,1);
beamAngle = zeros(cycles,1);
motorSignal = zeros(cycles,1);
PIDsig = zeros(cycles,3);
PIDerr = zeros(cycles,4);
ballPixels = zeros(cycles,2);
beamPixels = zeros(cycles,2);
sampletime = zeros(cycles,1);
pause(0.001);

%% BALANCE Controller Creation and Calibration
%create BALANCE system controller and set it up
Controller = BALANCEControlSystem(rpi,PWMpin,DIRpin);
Controller.SetUpHardware();

%Calibrate CV system
while(~Controller.CalibrateImage())
    disp("Calibrating");
    %     imshow(Controller.bimgLOW);
    pause(0.001)
end

%% Initialize PID
%Located the ball and set the objective of the control system
Controller.LocateFeatures();
Controller.SetObjective();

for i=1:15
    [statusball, statusbeam] = Controller.LocateFeatures();
    if(statusball && statusbeam)
        Controller.CalcPositionError();
        Controller.CalcThetaError();
        Controller.CalcMotorSignal();
    end
end

%Reset Integral Signal
Controller.I_err = [0,0];
Controller.I_sig = [0,0];

%% Main Program
%run program for the number of cycles
for i=1:cycles
    %fps timer start
    t = tic;

    %attempt to locate the ball and beam
    [statusball, statusbeam] = Controller.LocateFeatures();
    if(statusball && statusbeam) %if both the ball and beam is located
        %calculate PID signals
        Controller.CalcPositionError();
        Controller.CalcThetaError();
        Controller.CalcMotorSignal();

        %control the motor
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
    %needed to display image in realtime
    %pause(0.0001)


    %save controller data
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

    %Used to limit control rate

    %     while(toc(t)<(1/15))
    %     continue;
    %
    %     end
end

%stop the motor
Controller.StopMotor();

end