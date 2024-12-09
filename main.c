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

LRESULT CALLBACK CustomWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case 11:
                IGOR_MsgBox("Button 11 clicked", "Success", MB_OK | MB_ICONINFORMATION);
                printf("Button 11 clicked\n");
                break;
            }
        case WM_SETCURSOR:
            SetCursor(LoadCursor(NULL, IDC_ARROW));
            return TRUE;
        case WM_KEYDOWN:
            keys[wParam] = true;
            break;
        case WM_KEYUP:
            keys[wParam] = false;
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { // calls WinApi
    HWND window = IGOR_InitWindow(hInstance, nCmdShow, "Igor test", WINW /*primary screen width*/, WINH /*primary screen height*/, TRUE); // creates a window

    if (window != NULL) { // checks if the window is already
        printf("Window ready\n");
    
        IGOR_MsgBox("TEST MessageBox", "Success", MB_OK | MB_ICONASTERISK); // calls a message box

        IGOR_Button(window, hInstance, 11, "Button 11", 50, 50, 100, 30);

        SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)CustomWndProc);

        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            //IGOR_Rectangle(window, 0, 0, WINW, WINH, RGB(66, 52, 85), RGB(0, 0, 0));


        }
    }
    return 0;
}