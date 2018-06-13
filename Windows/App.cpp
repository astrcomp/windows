#include "App.h"

HINSTANCE App::hInstance = NULL;

LRESULT App::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

App::App()
{
	App::hInstance = GetModuleHandle(NULL);
}


App::~App()
{
}

int App::Run()
{
	MSG msg = { 0 };    //��������� ���������
	int iGetOk = 0;   //���������� ���������
	while ((iGetOk = GetMessage(&msg, NULL, 0, 0)) != 0) //���� ���������
	{
		//���� GetMessage ������ ������ - �����
		if (iGetOk == -1) return 3;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
