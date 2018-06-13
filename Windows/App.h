#pragma once
#include <Windows.h>
#include "Window.h"
class App
{
public:
	static HINSTANCE hInstance;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam,LPARAM lParam);
	App();
	~App();
	int Run();
};

