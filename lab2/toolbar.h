#pragma once

#include "framework.h"
#include "resource.h"
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

class ToolBar
{
protected:
	HWND hwndToolBar = NULL;
	LPARAM oldParam = NULL;
public:
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void PressBtn(HWND, LPARAM);
};