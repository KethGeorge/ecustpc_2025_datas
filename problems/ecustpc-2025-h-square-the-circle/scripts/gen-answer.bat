set argumentCount=0
for %%x in (%*) do Set /A argumentCount+=1
if not "%argumentCount%"=="4" pause 0
if "%1"=="" pause 0
if "%2"=="" pause 0
if not exist %1 pause 0
files\Square_The_Circle_Validator.exe --testset "%~3" --group "%~4" < %1
if errorlevel 1 pause 0
files\runexe.exe --interactor="-no-idleness-check -t 100s files\Square_The_Circle_Interactor.exe %1 output.txt" "solutions\Square_The_Circle_MainCorrect.exe"
if errorlevel 1 pause 0
if not exist output.txt pause 0
move output.txt %2
check.exe %1 %2 %2
:start
set error=1
if %errorlevel% equ 0 set error=0
if %errorlevel% equ 7 set error=0
if %error% equ 1 pause 0
:end
