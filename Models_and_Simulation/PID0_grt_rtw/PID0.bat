
set MATLAB=C:\MATLAB

cd .

if "%1"=="" ("C:\MATLAB\bin\win64\gmake"  -f PID0.mk all) else ("C:\MATLAB\bin\win64\gmake"  -f PID0.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1