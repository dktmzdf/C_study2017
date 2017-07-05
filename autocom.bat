
@echo off
if not exist C:\Users\KICT-06\Desktop\unity_3D_C_study\%1\%2 goto:EXIT
@echo on
cd engine
git add .
cd ..
cd %1
git add %1.sln
cd %2
rm -rf Debug
git add .
git commit -m "%2"
git push
cd ..
cd ..
:EXIT


