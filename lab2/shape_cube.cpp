#include "shape_cube.h"

void CubeShape::Show(HDC hdc)
{
	long x1, x2, y1, y2;

	RectShape::Show(hdc);

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1, y1, x1 + 30, y1 - 30);
	LineShape::Show(hdc);
	LineShape::Set(x1 + 30, y1 - 30, x2 + 30, y1 - 30);
	LineShape::Show(hdc);
	LineShape::Set(x2, y1, x2 + 30, y1 - 30);
	LineShape::Show(hdc);
	LineShape::Set(x2, y2, x2 + 30, y2 - 30);
	LineShape::Show(hdc);
	LineShape::Set(x2 + 30, y1 - 30, x2 + 30, y2 - 30);
	LineShape::Show(hdc);
	LineShape::Set(x1, y2, x1 + 30, y2 - 30);
	LineShape::Show(hdc);
	LineShape::Set(x1 + 30, y2 - 30, x2 + 30, y2 - 30);
	LineShape::Show(hdc);
	LineShape::Set(x1 + 30, y1 - 30, x1 + 30, y2 - 30);
	LineShape::Show(hdc);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}


void CubeShape::DrawRubberBand(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);

	long x1, x2, y1, y2;

	RectShape::DrawRubberBand(hWnd);

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1, y1, x1 + 30, y1 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::Set(x1 + 30, y1 - 30, x2 + 30, y1 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::Set(x2, y1, x2 + 30, y1 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::Set(x2, y2, x2 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::Set(x2 + 30, y1 - 30, x2 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::Set(x1, y2, x1 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::Set(x1 + 30, y2 - 30, x2 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);
	LineShape::Set(x1 + 30, y1 - 30, x1 + 30, y2 - 30);
	LineShape::DrawRubberBand(hWnd);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

Shape* CubeShape::copyShape() { return new CubeShape; }

void CubeShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_RECT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_SUPERLINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_CUBE, MF_CHECKED);
	}
}