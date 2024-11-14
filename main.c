/*
    IMPORTANT!!!

    THIS IS JUST AN EXAMPLE, NOT A PART OF THE LIBRARY
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    YOU CAN DELETE THIS FILE IF YOU KNOW HOW TO USE THIS LIBRARY
*/
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "IgorBox/essentials.h"

#define WINW (IGOR_GetScreenWidth())
#define WINH (IGOR_GetScreenHeight())

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { // calls WinMain
    HWND window = IGOR_InitWindow(hInstance, nCmdShow, "Igor test", WINW, WINH, TRUE); // creates a window

    float PLSPEED = 5.f;

    int PLX = 50;
    int PLY = 50;

    if (window != NULL) { // checks if the window is already
        printf("Window ready");

        IGOR_RoundRect(window, 30, 0, 100, 50, RGB(0,0,255), RGB(255,0,0), 20,20);

        IGOR_Rectangle(window, PLX, PLY, 20, 50, RGB(255,255,255), RGB(255,255,255));
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            IGOR_Rectangle(window, 0, 0, WINW, WINH, RGB(0, 0, 0), RGB(0, 0, 0));
            IGOR_Rectangle(window, PLX, PLY, 20, 50, RGB(255,255,255), RGB(255,255,255));

            if (IGOR_IsKeyDown('A')) {
                PLX -= PLSPEED;
                IGOR_Rectangle(window, PLX, PLY, 20, 50, RGB(0,0,25), RGB(25,0,0));
            }
            if (IGOR_IsKeyDown('D')) {
            PLX += PLSPEED;
            IGOR_Rectangle(window, PLX, PLY, 20, 50, RGB(0,0,25), RGB(25,0,0));
            }
}
        
        //IGOR_MsgBox("TEST MessageBox", "Success", MB_OK | MB_ICONERROR); // calls a message box
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}