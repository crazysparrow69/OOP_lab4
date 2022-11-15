#pragma once
#include "shape_line.h"
#include "shape_ellipse.h"

class LineOOShape : public LineShape, public EllipseShape
{
public:
	virtual void Show(HDC);
	void DrawRubberBand(HWND);
	Shape* copyShape();
	void OnInitMenuPopup(HWND, WPARAM);
};