@echo off
g++ -o MyProjectXRay.exe src\*.cpp
echo Running the program...
MyProjectXRay.exe assets\Chest.ppm 2 > assets\image.ppm
echo Output saved to assets\image.ppm
pause