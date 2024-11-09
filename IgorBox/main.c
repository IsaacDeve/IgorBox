#include <windows.h>
#include <winuser.h>

const char Window_Name[] = "oleg";
int width = 500;
int height = 500;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


    WNDCLASSEX wc = {};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = Window_Name;

    wc.cbSize = sizeof(WNDCLASSEX);
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx(
        WS_EX_TOPMOST,
         Window_Name,
          "My First Window",
           WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, 
            CW_USEDEFAULT,
            500, 500,
            NULL,
            NULL,
            hInstance,
            NULL);
    
    
    if (hWnd == NULL)
    {
        MessageBox(NULL, "Failed to create window", "Error", MB_OK);
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}