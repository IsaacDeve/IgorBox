/*
    IMPORTANT!!!

    THIS IS JUST AN EXAMPLE, NOT A PART OF THE LIBRARY
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    YOU CAN DELETE THIS FILE IF YOU KNOW HOW TO USE THIS LIBRARY
*/

#include <windows.h>
#include <stdbool.h>
#include "IgorBox/essentials.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { // calls WinMain
    HWND window = IGOR_InitWindow(hInstance, nCmdShow, "Igor test", 500, 500, TRUE); // creates a window

    if (window != NULL) { // checks if the window is already

        //IGOR_Button(window, hInstance, "Igoryanchez", 500, 50, 100, 30);
        HWND pizdyuk = IGOR_Button(window, hInstance, "Eblan", 100, 100, 100, 30);

        HWND pizdyuk2 = IGOR_Button(window, hInstance, "Eblan", 100, 20, 100, 30);
        
        //IGOR_MsgBox("TEST MessageBox", "Success", MB_OK | MB_ICONERROR); // calls a message box
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}
