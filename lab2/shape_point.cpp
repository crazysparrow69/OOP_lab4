#include "shape_point.h"

void PointShape::Show(HDC hdc)
{
	SetPixel(hdc, xs2, ys2, 0x00000000);
	SetPixel(hdc, xs2 - 1, ys2, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2, 0x00000000);
	SetPixel(hdc, xs2, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2, ys2 + 1, 0x00000000);
	SetPixel(hdc, xs2 - 1, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2 - 1, 0x00000000);
	SetPixel(hdc, xs2 - 1, ys2 + 1, 0x00000000);
	SetPixel(hdc, xs2 + 1, ys2 + 1, 0x00000000);
}

void PointShape::DrawRubberBand(HWND hWnd) { }

Shape* PointShape::copyShape() { return new PointShape; }

void PointShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_POINT, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_SUPERLINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_CUBE, MF_UNCHECKED);
	}
}