#include "stdafx.h"

extern void win32_Printf(HWND,TCHAR *,...);

int addTen(int b)
{
	b += 10;
	return b;
}

int *addTen2(int *b)
{
	*b += 10;
	return b;
}
int addTen3(int &b)
{
	b += 10;
	return b;
}

int *addTen4(int b)
{
	b += 10;
	return &b;
}


void testProc1(HWND hWnd) 
{
	win32_Printf(hWnd, L"testProcf");

	int val_a, c;
	val_a = 5;
	c = addTen(val_a);

	win32_Printf(hWnd,L"%d",c);

	addTen2(&c);

	win32_Printf(hWnd, L"%d", c);

	addTen3(c);

	win32_Printf(hWnd, L"%d", c);

	int *ap = addTen4(c);

	win32_Printf(hWnd, L"%d", *ap);
	*ap = 0;

	int *app;
	*app = c;

	win32_Printf(hWnd, L"%d", app);
}