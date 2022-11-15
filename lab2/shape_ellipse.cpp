#include "shape_ellipse.h"

void EllipseShape::Show(HDC hdc)
{
    HBRUSH hBrush, hBrushOld;
    hBrush = (HBRUSH)CreateSolidBrush(RGB(170, 74, 68));
    hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

    int sizeX = xs1 - xs2;
    int sizeY = ys1 - ys2;
    Ellipse(hdc, xs1 - sizeX, ys1 - sizeY, xs1 + sizeX, ys1 + sizeY);

    SelectObject(hdc, hBrushOld);
    DeleteObject(hBrush);
}

void EllipseShape::DrawRubberBand(HWND hWnd)
{
    HPEN hPenOld, hPen;
    HDC hdc;
    hdc = GetDC(hWnd);
    SetROP2(hdc, R2_NOTXORPEN);
    hPen = CreatePen(PS_DOT, 1, 0);
    hPenOld = (HPEN)SelectObject(hdc, hPen);

    int sizeX = xs1 - xs2;
    int sizeY = ys1 - ys2;
    Ellipse(hdc, xs1 - sizeX, ys1 - sizeY, xs1 + sizeX, ys1 + sizeY);

    SelectObject(hdc, hPenOld);
    DeleteObject(hPen);
    ReleaseDC(hWnd, hdc);
}

Shape* EllipseShape::copyShape() { return new EllipseShape; }

void EllipseShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
    HMENU hMenu, hSubMenu;
    hMenu = GetMenu(hWnd);
    hSubMenu = GetSubMenu(hMenu, 1);
    if ((HMENU)wParam == hSubMenu)
    {
        CheckMenuItem(hSubMenu, ID_POINT, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_LINE, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_RECT, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_ELLIPSE, MF_CHECKED);
        CheckMenuItem(hSubMenu, ID_SUPERLINE, MF_UNCHECKED);
        CheckMenuItem(hSubMenu, ID_CUBE, MF_UNCHECKED);
    }
}