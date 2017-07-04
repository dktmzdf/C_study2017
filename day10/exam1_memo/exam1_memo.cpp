// exam1_memo.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "exam1_memo.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK procMemoView(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK procMemoIns(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK procMemoDel(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM1_MEMO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM1_MEMO));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM1_MEMO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM1_MEMO);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
#include "../../engine/mywin32_engine.h"
TCHAR g_szDBBufferDB[1024] = L"helloworldgoodmornig";
int g_nTableLength[256] = { 5,5,4,6};
int g_nTableStartIndex[256] = { 0,5,10,14 };
int g_nStringCount = 4;
TCHAR *g_ptrStartBuffer;
int g_nTailIndex = 21;
HWND g_hOutputLogBox;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
		TCHAR *g_ptrStartBuffer = g_szDBBufferDB;
		g_hOutputLogBox = mywin32_engine::makeTextBox(hWnd, 0, 0, 320, 240, 5001);
		SetWindowText(g_hOutputLogBox, g_szDBBufferDB);
	}
	break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
			case ID_MEMO_INS:
			{
				DialogBox(hInst, MAKEINTRESOURCE(IDD_INSERT), hWnd, procMemoIns);
			}
			break;
			case ID_MEMO_DEL:
			{
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DEL), hWnd, procMemoDel);
			}
			break;
			case ID_MEMO_SEL:
			{
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_VIEW), hWnd, procMemoView);
			}
			break;
			case ID_DUMP:
			{
				TCHAR szBuf[1024];
				int nBufIndex = 0;
				for (int i = 0; i < g_nStringCount; i++) {
					int nStartIndex = g_nTableStartIndex[i];
					int nLength = g_nTableLength[i];
					for (int j = 0; j < nLength; j++) {
						szBuf[nBufIndex++] = g_szDBBufferDB[nStartIndex + j];
					}
					szBuf[nBufIndex++] = L'\n';
					
				}
				szBuf[nBufIndex++] = L'\0';
				SetWindowText(g_hOutputLogBox, szBuf);
			}
			break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK procMemoIns(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK )
		{
			
			TCHAR szBuf[256];
			TCHAR *ptrStartAt = &(g_szDBBufferDB[g_nTailIndex]);
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_INS), szBuf, 256);
			TCHAR *ptrSrc = szBuf;
			//ptrStartAt--;
			//lstrcpyW(ptrStartAt,ptrSrc);

			wcscat(g_szDBBufferDB, szBuf);
			
			g_nTableStartIndex[g_nStringCount] = g_nTailIndex;
			g_nTableLength[g_nStringCount] = wcslen(szBuf);
			g_nTailIndex += wcslen(szBuf);
			g_nStringCount++;
			
			SetWindowText(g_hOutputLogBox, g_szDBBufferDB);
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK procMemoDel(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			TCHAR szBuf[256];
			TCHAR *ptrStartAt = g_szDBBufferDB;
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_DEL), szBuf, 256);
			int nIndex = _wtoi(szBuf);
			//g_nTailIndex -= g_nTableLength[nIndex];
			g_nStringCount--;
			for (int i = nIndex; i < g_nStringCount; i++) {
				g_nTableStartIndex[nIndex] = g_nTableStartIndex[nIndex+1];
				g_nTableLength[nIndex] = g_nTableLength[nIndex+1];
			}
			
			/*
			TCHAR szBuf[256];
			TCHAR *ptrStartAt = g_szDBBufferDB;
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_DEL), szBuf, 256);
			int nIndex = _wtoi(szBuf);
			
			TCHAR *ptrTempBuf = &(ptrStartAt[g_nTableStartIndex[nIndex]]);
			ptrStartAt += g_nTableStartIndex[nIndex - 1];
			lstrcpyW(ptrStartAt, ptrTempBuf);
			ptrStartAt[g_nTailIndex] = 0x00;

			for (int i = nIndex-1; i < 255; i++) {
				if (i != 0) {
					g_nTableStartIndex[i] -= g_nTableStartIndex[nIndex - 1];
					//g_nTableStartIndex[i] -= g_nTableStartIndex[i + 1];
				}
				g_nTableLength[i] = g_nTableLength[i + 1];
				
				
			}
			g_nTailIndex -= g_nTableLength[nIndex - 1];
			g_nStringCount--;
			*/
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
			break;
	}
	return (INT_PTR)FALSE;
}
// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK procMemoView(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			TCHAR szBuf[256];
			
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_SEL), szBuf, 256);
			int nSel = _wtoi(szBuf);

			
			int nStartPos = g_nTableStartIndex[nSel];
			int nLength = g_nTableLength[nSel];
			TCHAR *pSrc = &(g_szDBBufferDB[nStartPos]);
			TCHAR *pTar = szBuf;

			int i = 0;
			for (i = 0; i < nLength; i++)
			{
				*(pTar++) = *(pSrc++);
//				szBuf[i] = g_szDBBufferDB[nStartPos+i];
			}
			pTar = 0x00;
			SetWindowText(g_hOutputLogBox,pTar);
			EndDialog(hDlg, LOWORD(wParam));

			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
			break;
	}
	return (INT_PTR)FALSE;
}
