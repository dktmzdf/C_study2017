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
	char *ptr = getBuf1();//�����ͷ� �Լ����� �������� ���ÿ��� ���� ���� ���ϴ°��� ���� �ֱ⿡ �ٸ� �Լ��� �θ��� ���� ����
	ptr[0] = '1';
	ptr[1] = '2';
	ptr[2] = '3';
	ptr[3] = '4';
	ptr[4] = '5';

	win32_Printf(hWnd, L"%d", ptr[0]);

	ptr = getBuf2();//������ ����ϴ� ���±��� ������ �ٽ� ���µ�

	win32_Printf(hWnd, L"%d", ptr[0]);
}