#include "essentials.h"

void IGOR_Rectangle(HWND win, int x, int y, int width, int height, COLORREF fillCol, COLORREF borderCol) {
    HDC hdc = GetDC(win);

    SelectObject(hdc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(hdc, fillCol);

    SelectObject(hdc, GetStockObject(DC_PEN));
    SetDCPenColor(hdc, borderCol);

    Rectangle(hdc, x, y, x + width, y + height);
    ReleaseDC(win, hdc);
}

void IGOR_Ellipse(HWND win, int x, int y, int width, int height, COLORREF fillCol, COLORREF borderCol) {
    HDC hdc = GetDC(win);

    SelectObject(hdc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(hdc, fillCol);

    SelectObject(hdc, GetStockObject(DC_PEN));
    SetDCPenColor(hdc, borderCol);

    Ellipse(hdc, x, y, x + width, y + height);
    ReleaseDC(win, hdc);
}

void IGOR_RoundRect(HWND win, int x, int y, int width, int height, COLORREF fillCol, COLORREF borderCol, int radiusX, int radiusY) {
    HDC hdc = GetDC(win);

    SelectObject(hdc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(hdc, fillCol);

    SelectObject(hdc, GetStockObject(DC_PEN));
    SetDCPenColor(hdc, borderCol);

    RoundRect(hdc, x, y, x + width, y + height, radiusX, radiusY);
    ReleaseDC(win, hdc);
}