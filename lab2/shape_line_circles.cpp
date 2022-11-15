#include "shape_line_circles.h"

void LineOOShape::Show(HDC hdc)
{
	long x1, x2, y1, y2;

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1 - 10, y1 - 10, x2 - 10, y2 - 10);
	LineShape::Show(hdc);

	EllipseShape::Set(x1 - 10, y1 - 10, x1 + 10, y1 + 10);
	EllipseShape::Show(hdc);

	EllipseShape::Set(x2 - 10, y2 - 10, x2 + 10, y2 + 10);
	EllipseShape::Show(hdc);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

void LineOOShape::DrawRubberBand(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);

	long x1, x2, y1, y2;

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1 - 10, y1 - 10, x2 - 10, y2 - 10);
	LineShape::DrawRubberBand(hWnd);

	EllipseShape::Set(x1 - 10, y1 - 10, x1 + 10, y1 + 10);
	EllipseShape::DrawRubberBand(hWnd);

	EllipseShape::Set(x2 - 10, y2 - 10, x2 + 10, y2 + 10);
	EllipseShape::DrawRubberBand(hWnd);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

Shape* LineOOShape::copyShape() { return new LineOOShape; }

void LineOOShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
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
		CheckMenuItem(hSubMenu, ID_SUPERLINE, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_CUBE, MF_UNCHECKED);
	}
}