@echo off
color 09
title IgorBox Compiler
gcc main.c IgorBox/essentials.c IgorBox/shapes.c -o IgorBox_Example_App -lgdi32

pause