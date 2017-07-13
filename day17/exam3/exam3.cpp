// exam3.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "exam3.h"

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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.
	plusEngine::startUpGdiPlus();
    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM3));

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
	plusEngine::CloseGdiPlus();
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM3);
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
irr::core::vector2df g_vObjPos;
irr::f64 g_fObjRotation;

void drawObject(Graphics *grp, irr::core::vector2df *pObjPoly,Pen *pen,irr::core::vector2df pos,irr::f64 fRotation)
{
	//irr::core::vector2df *pObjPoly = testObjPoly1;

	Matrix tempMat;
	grp->GetTransform(&tempMat);
	grp->TranslateTransform(pos.X, pos.Y);//���������� ��� ������
	grp->RotateTransform(fRotation);

	Matrix wMat;//���簪 ���ϱ�
	grp->GetTransform(&wMat);
	//wMat.Translate(-160, -120);

	for (int i = 0; i < 4; i++)
	{
		irr::core::vector2df start = pObjPoly[i];

		irr::core::vector2df end = pObjPoly[(i + 1) % 4];
		grp->DrawLine(pen, start.X, start.Y, end.X, end.Y);

		PointF _startX(start.X, start.Y);
		wMat.TransformPoints(&_startX);

		plusEngine::printf(grp, start.X, start.Y, L"(%.1lf,%.1lf)", _startX.X, _startX.Y);
	}
	grp->SetTransform(&tempMat);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
	{
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_LEFT:
		{
			g_vObjPos.X -= 1;
		}
		break;
		case VK_RIGHT:
		{
			g_vObjPos.X += 1;
		}
		break;
		case VK_UP:
		{
			g_vObjPos.Y -= 1;
		}
		break;
		case VK_DOWN:
		{
			g_vObjPos.Y += 1;
		}
		break;
		case 'A':
		{
			g_fObjRotation -= 8;
		}
		break;
		case 'S':
		{
			g_fObjRotation += 8;
		}
		break;
		default:
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
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
			Graphics grp(hdc);
			Pen pen(Color(0, 0, 0));
			//ȭ�� ����ǥ�� 
			grp.DrawLine(&pen, 0, 120, 320, 120);
			grp.DrawLine(&pen, 160, 0, 160, 240);
			grp.DrawRectangle(&pen, 0, 0, 320, 240);
			grp.SetTransform(&Matrix(1, 0, 0, 1, 160, 120));



			irr::core::vector2df testObjPoly1[4] = {
				irr::core::vector2df(-40,20),
				irr::core::vector2df(40,20),
				irr::core::vector2df(40,-20),
				irr::core::vector2df(-40,-20)
				
			};
			

			//��� ��ü �׸���
			irr::core::vector2df obj1_pos(-100, -100);
			irr::f64 obj1_rot = 30;
			drawObject(&grp, testObjPoly1, &pen, obj1_pos, obj1_rot);//obj1
			drawObject(&grp, testObjPoly1, &pen, g_vObjPos, g_fObjRotation);//obj2
			

			irr::core::vector2df worldpos_obj1[4];
			irr::core::vector2df worldpos_obj2[4];
			
			//obj1->world;
			{
				Matrix world_mat;
				world_mat.Translate(obj1_pos.X, obj1_pos.Y);
				world_mat.Rotate(obj1_rot);
				for (int i = 0; i < 4; i++)
				{
					PointF temp(testObjPoly1[i].X, testObjPoly1[i].Y);
					world_mat.TransformPoints(&temp);
					worldpos_obj1[i].X = temp.X;
					worldpos_obj1[i].Y = temp.Y;
				}
			}
			//obj2->world;
			{
				Matrix world_mat;
				world_mat.Translate(g_vObjPos.X, g_vObjPos.Y);
				world_mat.Rotate(g_fObjRotation);
				for (int i = 0; i < 4; i++)
				{
					PointF temp(testObjPoly1[i].X, testObjPoly1[i].Y);
					world_mat.TransformPoints(&temp);
					worldpos_obj2[i].X = temp.X;
					worldpos_obj2[i].Y = temp.Y;
				}
			}


			
			//�浹ó��
			//��ó��
			/*
			{
				irr::f32 result[4][4];
				//��� ������ �����ʿ� ������ �� �����̸� �� ������ ������ ���� �̿���
				for (int i = 0; i < 4; i++) {
					



					for (int j = 0; j < 4; j++) {
						irr::core::vector2df start = worldpos_obj1[j];
						irr::core::vector2df end = worldpos_obj1[j + 1];
						grp.DrawLine(&pen, start.X, start.Y, end.X, end.Y);
						irr::core::line2df line1(start.X, start.Y, end.X, end.Y);
						result[i][j] = line1.getPointOrientation(worldpos_obj2[i]);
					}



					if (result[i][0] < 0 && result[i][1] < 0 && result[i][2] < 0 && result[i][3] < 0) {
						plusEngine::printf(&grp, worldpos_obj2[i].X, worldpos_obj2[i].Y, L"��");
					}
					//
					else {
						plusEngine::printf(&grp, worldpos_obj2[i].X, worldpos_obj2[i].Y, L"��");
					}
				}
			}*/
			//irr::core::line2df line2(worldpos_obj2[i], worldpos_obj2[(i + 1) % 4]);
			//��

			for (int i = 0; i < 4; i++) {
				irr::core::line2df line1(worldpos_obj2[i], worldpos_obj2[(i + 1) % 4]);
				for (int j = 0; j < 4; j++) {
					irr::core::line2df line2;
					line2.setLine(worldpos_obj1[j], worldpos_obj1[(j + 1) % 4]);

					irr::core::vector2df colPt;
					if (line1.intersectWith(line2, colPt)) {
						grp.DrawRectangle(&pen, colPt.X - 4, colPt.Y - 4, 8.0, 8.0);
					}
				}
			}
			
			grp.ResetTransform();
			

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
