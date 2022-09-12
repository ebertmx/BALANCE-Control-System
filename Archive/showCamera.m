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
end

while true

    Controller.LocateFeatures();
    %Controller.ShowImage();
    subplot(1,2,1)
    imshow(Controller.bimgHIGH)
    subplot(1,2,2)
    imshow(Controller.bimgLOW)
    pause(0.001);

end