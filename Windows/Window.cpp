#include "Window.h"


Window::Window()
{
	LPCTSTR lpzClass = TEXT("My Window Class!");

	// вычисление координат центра экрана
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect); // разрешение экрана
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 2 - 75;

	WNDCLASS wcWindowClass = { 0 };
	//адрес ф-ции обработки сообщений
	wcWindowClass.lpfnWndProc = App::WndProc;
	//стиль окна
	wcWindowClass.style = CS_HREDRAW | CS_VREDRAW;
	//дискриптор экземпл€ра приложени€
	//название класса
	wcWindowClass.hInstance = GetModuleHandle(NULL);
	wcWindowClass.lpszClassName = lpzClass;
	//загрузка курсора
	wcWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	//загрузка цвета окон
	wcWindowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;

	//регистраци€ класса
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
