#pragma once
#include "shape_line.h"
#include "shape_rect.h"

class CubeShape : public LineShape, public RectShape
{
public:
	virtual void Show(HDC);
	void DrawRubberBand(HWND);
	Shape* copyShape();
	void OnInitMenuPopup(HWND, WPARAM);
};