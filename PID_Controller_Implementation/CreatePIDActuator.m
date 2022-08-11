Kp = 26.484;
Ki = 22.299;
Kd = 7.312;
N = 25.504;
Ts = 1/20;
syms z n
APID = pid(Kp,Ki,Kd,N,'IFormula','ForwardEuler','DFormula','ForwardEuler');
APID = c2d(APID,Ts, 'zoh');

ATF = tf(APID);
[num,dem] = tfdata(ATF);
ADIFF = idpoly(dem,num,'NoiseVariance',0);

%ActuatorPID = Kp + Ki*Ts*1/(z-1) + Kd * N/(1+N*Ts*1/(z-1));
