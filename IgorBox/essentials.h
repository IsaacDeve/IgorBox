#ifndef ESSENTIALS_H
#define ESSENTIALS_H

#include <windows.h>
#include <stdbool.h>

//ALL FUNCTIONS INITIALIZED HERE
LRESULT CALLBACK CustomWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void IGOR_MsgBox(const char *content, const char *title, UINT btn);
//void IGOR_Window_ChangeTitle(HWND *win, const char *title);
HWND IGOR_InitWindow(HINSTANCE hInstance, int nCmdShow, const char *title, int width, int height, BOOL resize);

//screen
int IGOR_GetScreenWidth();
int IGOR_GetScreenHeight();

void IGOR_LockFPS(int targetFPS);

//CONTROLS
HWND IGOR_Button(HWND pwindow, HINSTANCE hInstance, int id, const char *text, int x, int y, int width, int height);


//input

extern bool keys[256];

bool IGOR_IsKeyDown(int key);

//shapes

void IGOR_Rectangle(HWND win, int x, int y, int width, int height, COLORREF fillCol, COLORREF borderCol);
void IGOR_Ellipse(HWND win, int x, int y, int width, int height, COLORREF fillCol, COLORREF borderCol);
void IGOR_RoundRect(HWND win, int x, int y, int width, int height, COLORREF fillCol, COLORREF borderCol, int radiusX, int radiusY);

#endif