close all
clear
load("FullFPSloosegear.mat")
rangelow = 601;
rangehigh = 849;

maxv = positionError(rangelow);
rangesize = rangehigh-rangelow+1;

time = zeros(rangesize,1);
for i = 1:rangesize
    time(i) = sum(sampletime(1:i));
end

p = positionError(rangelow:rangehigh);
t = thetaError(rangelow:rangehigh);
m = motorSignal(rangelow:rangehigh);
a = beamAngle(rangelow:rangehigh);

x = zeros(rangesize,1);
a90p = zeros(rangesize,1)+(maxv-maxv*0.9);
a10 = zeros(rangesize,1)+(maxv-maxv*0.1);
a90m = zeros(rangesize,1)-(maxv-maxv*0.9);

subplot(2,1,1)
hold on
plot(time,a90p,'c--');
plot(time,a90m,'g--');
plot(time,a10,'g--');


plot(time,x,'b--');
plot(time,p, 'k-');
plot(time,t,'r-');
hold off
legend('+90%','-90%','10%','Objective Position','Position Error', 'Angle Error')
xlabel('time (s)');
ylabel('value');

subplot(2,1,2)
hold on
plot(time,x,'b--');
plot(time,m, 'k-');
plot(time,a,'r-');
hold off
legend('Objective Position', 'motor signal','beam angle')
xlabel('time (s)');
ylabel('value');
