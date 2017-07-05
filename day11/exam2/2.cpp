#include "stdafx.h"

extern void win32_Printf(HWND, TCHAR *, ...);
//extern void DisplayLog(HWND);
//extern void (HWND);
char *getBuf1()
{
	char buf[5];
	return buf;
}

char *getBuf2()
{
	char buf[5];
	return buf;
}

void testProc2(HWND hWnd)
{
	char *ptr = getBuf1();//포인터로 함수에서 받지말것 스택에서 관리 받지 못하는곳에 값이 있기에 다른 함수를 부르면 값이 깨짐
	ptr[0] = '1';
	ptr[1] = '2';
	ptr[2] = '3';
	ptr[3] = '4';
	ptr[4] = '5';

	win32_Printf(hWnd, L"%d", ptr[0]);

	ptr = getBuf2();//이전에 사용하던 스태그이 영역이 다시 리셋됨

	win32_Printf(hWnd, L"%d", ptr[0]);
}