#include "shape_rect.h"

void RectShape::Show(HDC hdc)
{
	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs2, ys1);
	LineTo(hdc, xs2, ys2);
	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs1, ys2);
	LineTo(hdc, xs2, ys2);
}

void RectShape::DrawRubberBand(HWND hWnd)
{
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	RectShape::Show(hdc);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);

}

Shape* RectShape::copyShape() { return new RectShape; }

void RectShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_RECT, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_SUPERLINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_CUBE, MF_UNCHECKED);
	}
}