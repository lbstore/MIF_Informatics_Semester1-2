@echo off
"c:\programming\fps\fpk106\bin\win32\ldw.exe"     -o "c:\programming\pascal\task 3\final version\Uzduotis3Final.exe" "link.res" exp.$$$
if errorlevel 1 goto linkend
goto end
:asmend
echo An error occured while assembling %THEFILE%
goto end
:linkend
echo An error occured while linking %THEFILE%
:end
