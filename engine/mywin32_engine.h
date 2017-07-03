#pragma once
namespace mywin32_engine {
	namespace util {
		//,�� ���е� ���ڿ��� �Ǽ��� �迭�� �ִ´�. ��ȯ���� �������� �Ǽ��� ����
		int Buffer2DoubleArray(TCHAR *szBuf,double *pResult)
		{
			int nCount = 0;
			TCHAR szTemp[256];
			TCHAR *pwc;
			pwc = wcstok(szBuf, L", ");
			pResult[nCount++] = _wtof(pwc);
			while (pwc != NULL) {
				pwc = wcstok(NULL, L", ");//NULL�� �־��ָ� ���� �־� ����� ��� ��
				if (pwc != NULL) {
					pResult[nCount++] = _wtof(pwc);
				}

			}
			return nCount;
		}
	}

	void makeMiniEditBox(HWND hWnd, int xPos, int yPos, int nHandle)
	{
		CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER,
			xPos, yPos, 100, 25, hWnd, (HMENU)nHandle, hInst, NULL);
	}
	void makeEditBox(HWND hWnd, int xPos, int yPos,int nWdith, int nHandle)
	{
		CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER,
			xPos, yPos, nWdith, 25, hWnd, (HMENU)nHandle, hInst, NULL);
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
	double GetControlValueDouble(HWND hWnd, int nHandle) {
		TCHAR szBuf[256];
		GetWindowText(GetDlgItem(hWnd, nHandle), szBuf, 256);
		double result = _wtof(szBuf);

		return result;
	}
	void SetControlValueInt(HWND hWnd, int nId, int nValue) {
		TCHAR szBuf[256];
		swprintf_s(szBuf, 256, L"%d", nValue);
		SetWindowText(GetDlgItem(hWnd, nId), szBuf);
	}
	void SetControlValueDouble(HWND hWnd, int nId, double nValue) {
		TCHAR szBuf[256];
		swprintf_s(szBuf, 256, L"%lf", nValue);
		SetWindowText(GetDlgItem(hWnd, nId), szBuf);
	}
}