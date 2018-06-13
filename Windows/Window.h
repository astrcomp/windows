#pragma once
#include "App.h"
class Window
{
private:
	HWND hWnd;
public:
	void Show();
	void SetWnd();
	Window();
	~Window();
};

