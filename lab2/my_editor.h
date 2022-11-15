#pragma once
#include "shape.h"
#include "toolbar.h"
#define MY_SHAPE_ARRAY_SIZE 123

class MyEditor
{
private:
	static Shape* pcshape[MY_SHAPE_ARRAY_SIZE];
	static int nCurrentIndex;
	ToolBar toolbar;
	Shape* currShape;
	BOOL isPainting = false;
	POINT pt;
public:
	void Start(HWND, Shape*, LPARAM);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
	void OnCreate(HWND, HINSTANCE);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnSize(HWND);
};
