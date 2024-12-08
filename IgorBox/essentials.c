#include "essentials.h"
#include <stdbool.h>

const char ClassWindow_Name[] = "IgorBox_Window";

bool keys[256] = {0};

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
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

void IGOR_LockFPS(int targetFPS)
{
    static DWORD lastTime = 0;
    DWORD currentTime = GetTickCount();
    int frameTime = 1000 / targetFPS;

    if (lastTime == 0) {
        lastTime = currentTime;
    }

    if (currentTime - lastTime < frameTime) {
        Sleep(frameTime - (currentTime - lastTime));
    }
    lastTime = GetTickCount();
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

HWND IGOR_Button(HWND pwindow, HINSTANCE hInstance, int id, const char *text, int x, int y, int width, int height)
{
    return CreateWindow(
        "BUTTON",
        text,
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        x, y,
        width, height,
        pwindow,
        (HMENU)(uintptr_t)id,
        hInstance,
        NULL
    );
}

int IGOR_GetScreenWidth()
{ return (int)GetSystemMetrics(SM_CXSCREEN); }

int IGOR_GetScreenHeight()
{ return (int)GetSystemMetrics(SM_CYSCREEN); }