@echo off
color 09
title IgorBox Compiler
gcc main.c IgorBox/essentials.c -o IgorBox -lgdi32

pause