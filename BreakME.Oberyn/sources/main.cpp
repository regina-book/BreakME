#define _WIN32_WINNT 0x0500
#include<windows.h>
#include <mmsystem.h>
#include "resource.h"

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
BOOL PlayResource(LPCWSTR lpName);
BOOL check(char *buffer);

/*  Make the class name into a global variable  */
char szClassName[] = "BreakME.Oberyn";

int WINAPI WinMain (HINSTANCE hThisInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszArgument,
					int nCmdShow)
{
	HWND hwnd; /* This is the handle for our window */
	MSG messages; /* Here messages to the application are saved */
	WNDCLASSEX wincl; /* Data structure for the windowclass */

	/* The Window structure */
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = (LPCWSTR) szClassName;
	wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
	wincl.style = CS_DBLCLKS; /* Catch double-clicks */
	wincl.cbSize = sizeof (WNDCLASSEX);

	/* Use default icon and mouse-pointer */
	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL; /* No menu */
	wincl.cbClsExtra = 0; /* No extra bytes after the window class */
	wincl.cbWndExtra = 0; /* structure or the window instance */
	/* Use Windows's default colour as the background of the window */
	wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx (&wincl))
		return 0;

	/* The class is registered, let's create the program*/
	hwnd = CreateWindowEx (
		0, /* Extended possibilites for variation */
		(LPCWSTR) szClassName, /* Classname */
		TEXT("BreakME.Oberyn"), /* Title Text */
		(WS_VISIBLE | WS_OVERLAPPEDWINDOW), /* default window */
		CW_USEDEFAULT, /* Windows decides the position */
		CW_USEDEFAULT, /* where the window ends up on the screen */
		360, /* The programs width */
		240, /* and height in pixels */
		NULL, /* The window is a child-window to desktop */
		NULL, /* No menu */
		hThisInstance, /* Program Instance handler */
		NULL /* No Window Creation data */
		);
	/* Run the message loop. It will run until GetMessage() returns 0 */
	while (GetMessage (&messages, NULL, 0, 0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&messages);
		/* Send message to WindowProcedure */
		DispatchMessage(&messages);
	}
	/* The program return-value is 0 - The value that PostQuitMessage() gave */
	return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,
								 LPARAM lParam) {
									 wchar_t text[256] = {0};
									 switch (message) /* handle the messages */
									 {
									 case WM_CREATE:
										 txtEdit = CreateWindowEx(0, TEXT("EDIT"), TEXT("Oberyn :'("), WS_CHILD | WS_VISIBLE,
											 25, 125, 200, 20, hwnd, NULL, hThisInstance, NULL);

										 btnOk = CreateWindowEx(0, TEXT("BUTTON"), TEXT("Ok"), WS_CHILD | WS_VISIBLE, 230,
											 125, 40, 20, hwnd, NULL, hThisInstance, (LPVOID) NULL);

										 lblRight = CreateWindowEx(0, TEXT("STATIC"),
											 TEXT("Oh YEAH ! You are a PRINCE ! :D"), WS_CHILD, 80, 80, 120, 40,
											 hwnd, NULL, hThisInstance, NULL);

										 lblWrong = CreateWindowEx(0, TEXT("STATIC"),
											 TEXT("You wrong, any bottle of wine ?"), WS_CHILD, 220, 40, 120, 40,
											 hwnd, NULL, hThisInstance, NULL);

										 PlaySound(TEXT("SoundName"), hThisInstance, SND_RESOURCE | SND_ASYNC);
										 break;

									 case WM_ERASEBKGND:

										 hBmp = LoadBitmap(GetModuleHandle(NULL), TEXT("bitmapName"));
										 hdc = (HDC) wParam;
										 hdcmem = CreateCompatibleDC(hdc);
										 hOldBmp = (HBITMAP) SelectObject(hdcmem, hBmp);
										 BitBlt(hdc, 0, 0, 999, 999, hdcmem, 0, 0, SRCCOPY);
										 SelectObject(hdcmem, hOldBmp);
										 DeleteDC(hdcmem);
										 break;

									 case WM_COMMAND:
										 if (btnOk != NULL && lParam == (int) btnOk) {
											 GetWindowText(txtEdit, text, 255);
											 if (wcslen(text) > 0 && check(text)) {
												 ShowWindow(lblRight, SW_SHOW);
												 ShowWindow(lblWrong, SW_HIDE);
											 } else {
												 ShowWindow(lblRight, SW_HIDE);
												 ShowWindow(lblWrong, SW_SHOW);
											 }
										 }
										 break;

									 case WM_CLOSE:
										 DestroyWindow(GetConsoleWindow());
										 DestroyWindow(hwnd);
										 break;
									 case WM_DESTROY:
										 DestroyWindow(GetConsoleWindow());
										 DestroyWindow(hwnd);
										 PostQuitMessage(0); /* send a WM_QUIT to the message queue */
										 break;
									 default: /* for messages that we don't deal with */
										 return DefWindowProc(hwnd, message, wParam, lParam);
									 }

									 return 0;
}
