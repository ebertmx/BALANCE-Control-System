clear;
close all;
rpi = raspi();
PWMpin = 13;
DIRpin = 6;

pause(0.001);

%create Balancesystem controller and set it up
Controller = BALANCEControlSystem(rpi,PWMpin,DIRpin);
Controller.SetUpHardware();
Controller.RunMotorFor(1,0.2,4);
