#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#include <windows.h>

//ALL FUNCTIONS INITIALIZED HERE

void IGOR_MsgBox(const char *content, const char *title, UINT btn);
//void IGOR_Window_ChangeTitle(HWND *win, const char *title);
HWND IGOR_InitWindow(HINSTANCE hInstance, int nCmdShow, const char *title, int width, int height, BOOL resize);
HWND IGOR_Button(HWND parentHwnd, HINSTANCE hInstance, const char *buttonText, int x, int y, int width, int height);

//shapes

void IGOR_Rectangle(HWND win, int x, int y, int width, int height, COLORREF fillCol, COLORREF borderCol);

#endif
