Kp = 0.11064;
Ki = 0.00984;
Kd = 0.29818;
N = 4.9215;
Ts = 1/20;
syms z n
APID = pid(Kp,Ki,Kd,N,'IFormula','ForwardEuler','DFormula','ForwardEuler');
APID = c2d(APID,Ts, 'zoh');

ATF = tf(APID);
[num,dem] = tfdata(ATF);
ADIFF = idpoly(dem,num,'NoiseVariance',0);

%ActuatorPID = Kp + Ki*Ts*1/(z-1) + Kd * N/(1+N*Ts*1/(z-1));
