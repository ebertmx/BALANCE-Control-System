ICMOTOR = 0.0016120177; %kgm^2;
MASS = 110.8/1000; %kg;
DISPLACMENT = 60/1000; %m
JMOTOR = ICMOTOR + MASS*DISPLACMENT^2;
BMOTOR = 3.5077E-6;
KMOTOR = 0.0274;
RMOTOR = 4;
LMOTOR = 2.75E-6;
GR = 50/80;

s = tf('s');
TF_motor = GR*KMOTOR/(s*((JMOTOR*s+BMOTOR)*(LMOTOR*s+RMOTOR)+KMOTOR^2));
b = cell2mat(TF_motor.Numerator);
a = cell2mat(TF_motor.Denominator);
[A,B,C,D]= tf2ss(b,a);
