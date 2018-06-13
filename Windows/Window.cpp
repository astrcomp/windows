#include "Window.h"


Window::Window()
{
	LPCTSTR lpzClass = TEXT("My Window Class!");

	// ���������� ��������� ������ ������
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect); // ���������� ������
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 2 - 75;

	WNDCLASS wcWindowClass = { 0 };
	//����� �-��� ��������� ���������
	wcWindowClass.lpfnWndProc = App::WndProc;
	//����� ����
	wcWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	//���������� ���������� ����������
	//�������� ������
	wcWindowClass.hInstance = GetModuleHandle(NULL);
	wcWindowClass.lpszClassName = lpzClass;
	//�������� �������
	wcWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//�������� ����� ����
	wcWindowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;

	//����������� ������
	RegisterClass(&wcWindowClass);

	this->hWnd = CreateWindow(lpzClass, TEXT("Dialog Window"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, x, y, 300, 150, NULL, NULL,
		App::hInstance, NULL);

}


Window::~Window()
{
}


void Window::Show()
{
	UpdateWindow(this->hWnd);
}


void Window::SetWnd()
{

}
