#pragma once
void makeMiniEdit(HWND hWnd, int xPos, int yPos, int nHandle)
{
	CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | CBS_AUTOHSCROLL | WS_BORDER,
		xPos, yPos, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
}
void makeMiniButton(HWND hWnd, int xPos, int yPos, int nHandle, TCHAR *pszLabel)
{

	CreateWindow(L"button", pszLabel, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		xPos, yPos, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
}
int GetControlValueInt(HWND hWnd, int nHandle) {
	TCHAR szBuf[256];
	GetWindowText(GetDlgItem(hWnd, nHandle), szBuf, 256);
	int result = _wtoi(szBuf);

	return result;
}