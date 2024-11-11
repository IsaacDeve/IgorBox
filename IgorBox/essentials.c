#include "essentials.h"
#include <stdbool.h>

const char ClassWindow_Name[] = "IgorBox_Window";

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}

void IGOR_MsgBox(const char *content, const char *title, UINT btn) {
    MessageBox(NULL, content, title, btn);
}

HWND IGOR_InitWindow(HINSTANCE hInstance, int nCmdShow, const char *title, int width, int height, BOOL resize) {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = ClassWindow_Name;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClassEx(&wc)) {
        IGOR_MsgBox("Cant register class lmao", "error", MB_OK | MB_ICONERROR);
        return NULL;
    }

    DWORD style = WS_OVERLAPPEDWINDOW;
    if (!resize) {
        style &= ~WS_THICKFRAME;
        style &= ~WS_MAXIMIZEBOX;
    }

    HWND hWnd = CreateWindowEx(
        0,
        ClassWindow_Name,
        title,
        style,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hWnd == NULL) {
        IGOR_MsgBox("Failed to create window", "Error", MB_OK | MB_ICONERROR);
        return NULL;
    }

    //CONTROLS


    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return hWnd;
}

HWND IGOR_Button(HWND parentHwnd, HINSTANCE hInstance, const char *buttonText, int x, int y, int width, int height) {
HWND hwndButton = CreateWindowEx(
    0,
    "BUTTON",
    buttonText,
    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
    x, y, width, height,
    parentHwnd,
    (HMENU)1,
    hInstance,
    NULL
);

    return hwndButton;
}
