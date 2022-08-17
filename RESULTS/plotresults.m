<<<<<<< Updated upstream
% load ("actuatorcontrolsignal.mat")
% load("angleerror.mat")
% load("ballpixels.mat")
% load("ballposition.mat")
% load("beampixels.mat")
% load("PIDerrorsignal.mat")
% load("PIDmotorsignal.mat")
load("results3_wihttime.mat")

subplot(2,2,1)
hold on
plot(positionError, 'k-');
%plot(thetaError,'r-');
%plot(beamAngle, 'c-');
%plot(motorSignal,'b-');
hold off
legend('Position Error', 'Theta Error', 'Beam Angle', 'Motor Signal')
=======

>>>>>>> Stashed changes

close all
clear

load("alphaFilter75percent.mat")

% subplot(2,2,1)
% hold on
% plot(positionError,'k-')
% plot(thetaError,'r-')
% hold off
% legend('Position Error','Theta Error')
% 
% subplot(2,2,2)
% hold on
% plot(thetaError, 'k-')
% plot(PIDerr(:,1), 'c-');
% plot(PIDerr(:,2), 'r-');
% plot(PIDerr(:,3), 'g-');
% plot(PIDerr(:,4), 'b-');
% hold off
% legend('Theta Error', 'P', 'I', 'D', 'A')
% subplot(2,2,3);
% hold on
% plot(motorSignal, 'k-')
% plot(PIDsig(:,1), 'r-');
% plot(PIDsig(:,2), 'g-');
% plot(PIDsig(:,3), 'b-');
% hold off
% legend('motor signal', 'P', 'I', 'D')
% 
% subplot(2,2,4);
hold on
plot(beamPixels(500:800,1) ,'r-');
plot(beamPixels(500:800,2), 'b-')
plot(ballPixels(500:800,1), 'k-')
plot(ballPixels(500:800,2), 'c-')
hold off
legend('beam i', 'beam j', 'ball i', 'ball j')
<<<<<<< Updated upstream

clear;
close all;
=======
xlabel('Frames')
ylabel('Pixel Position')


>>>>>>> Stashed changes
