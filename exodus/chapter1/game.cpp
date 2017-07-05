#include "stdafx.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

//y*8 + x �� (x,y)��ġ
int g_MapRoom1[] = {
	3, 0, 0, 0, 0, 0, 0, 3,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	2, 2, 48, 2, 2, 2, 2, 2
};

int g_MapRoom2[] = {
	3, 0, 0, 0, 0, 0, 0, 3,
	1,14,14,14,14,14,14, 1,
	1,14,14,14,14,14,14, 1,
	1,14,1,14,14,1,14, 1,
	1,14,1,14,14,1,14, 1,
	1,14,1,14,14,1,14, 1,
	1,14,14,14,14,14,14, 1,
	2, 2, 48, 2, 2, 2, 2, 2
};
int g_MapAttrBlock[] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};

int g_nMapStatus = 1;


int g_nDoorXpos = 7;
int g_nDoorYpos = 2;

int g_nItemSwitchXPos = 5;
int g_nItemSwitchYPos = 4;
int g_nItemSwithchSprIndex = 46;
int g_nItemSwithchStatus = 0; //������ 0 1�̸� �۵���
//������ ����ġ ������Ʈ
int *g_nowMap;
int g_nPlayerXPos = 3;
int g_nPlayerYPos = 3;
#define GETLOCATEPLAYERTILE (g_nPlayerYPos * 8) + g_nPlayerXPos 

	const int g_nTileSize = 16;
	const int g_nTileXCount = 8;

	void drawTileIndex(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int nTileIndex)
	{
		//int nTileIndex = pTileLib[nPosX + nPosY * g_nTileXCount];
		//int nTileIndex = 14;
		pGrp->DrawImage(pImgBasicTile,
			Rect(nPosX * 16, nPosY * 16, g_nTileSize, g_nTileSize),
			g_nTileSize * (nTileIndex % g_nTileXCount), //���� x ��ġ
			g_nTileSize * (nTileIndex / g_nTileXCount),  //���� y ��ġ
			g_nTileSize, g_nTileSize,
			UnitPixel);
	}

void drawTile(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int *pMap)
{
	int nTileIndex = pMap[nPosX + nPosY * g_nTileXCount];
	drawTileIndex(pGrp, pImgBasicTile, nPosX, nPosY, nTileIndex);
}


DWORD g_dwGdiLoopFsm = 0;
void GDIPLUS_Loop(MSG &msg)
{
	//----------------------------------------------------------------------
	//gdi plus �ʱ�ȭ �ڵ� 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;

	// Initialize GDI+.
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//-----------------------------------------------------------------------

	{
		bool quit = false;
		//gdiplus �� �˴ٿ� �Ǳ����� ��ü���� �����Ǿ�� �ϹǷ� �Ϻη� �������������� �Ѵܰ� ������ ����ߴ�.
		Gdiplus::Rect rectScreen(0, 0, 320, 240);
		Bitmap bmpMem(rectScreen.Width, rectScreen.Height);
		Graphics* graphBackBuffer = Graphics::FromImage(&bmpMem);

		Pen penRed(Color(255, 0, 0));
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		Gdiplus::SolidBrush brushWhite(Color(255, 255, 255));
		FontFamily  fontFamily(L"����");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		static LONG prev_tick;
		static SYSTEMTIME time;

		Image imgBasicTile(L"../../res/basic_tile/basictiles.png");//16 x 16;
		Image imgPlayer(L"../../res/potrait/charater.png");//ũ�� x64 y64

		g_nowMap = g_MapRoom1;
		while (!quit) {

			if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
					quit = true;
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else {
				switch (g_dwGdiLoopFsm)
				{
				case 0:
					break;
				case 10:
				{
					GetSystemTime(&time);
					LONG time_ms = (time.wSecond * 1000) + time.wMilliseconds;
					float fDelta = (time_ms - prev_tick) / 1000.f;
					prev_tick = time_ms;
					//���� ����
					{
						if (g_nItemSwithchStatus == 0) {


							//����ġ �ִ��� �˻�
							if (g_nItemSwitchXPos == g_nPlayerXPos && g_nItemSwitchYPos == g_nPlayerYPos) {
								g_nItemSwithchStatus = 1;
								g_MapAttrBlock[8 * 7 + 2] = 0;//��������
								g_MapRoom1[8 * 7 + 2] = 50;
							}
							else {

							}
						}
						if (1 ==1 );
					}
					//������
					// Get DC
					HDC hdc = GetDC(msg.hwnd);
					{
						Graphics graphics(hdc);

						graphBackBuffer->FillRectangle(&brushBlack, rectScreen);


						//�����׸���
						for (int ix = 0; ix < 8; ix++) {
							for (int iy = 0; iy < 8; iy++) {
								drawTile(graphBackBuffer,
									&imgBasicTile,
									ix, iy,
									g_MapRoom1);
							}
						}
						if (g_nItemSwithchStatus == 0) {
							drawTileIndex(graphBackBuffer, &imgBasicTile, g_nItemSwitchXPos, g_nItemSwitchYPos, 47);
						}

						//�÷��̾�׸���
						graphBackBuffer->DrawImage(&imgPlayer,
							Rect((g_nPlayerXPos * 16) - 16 + 8, (g_nPlayerYPos * 16) - 16, 32, 32),//�����ġ // - 16�� ���߾����� �׸��� +8�� Ÿ�� ���� �ڿ� 32 32�� �� ũ��
							0, 64 * 2, 64, 64,//���� ��ġ
							UnitPixel
						);


						graphics.ScaleTransform(2, 2);
						graphics.DrawImage(&bmpMem, rectScreen);
						graphics.ResetTransform();
					}
					ReleaseDC(msg.hwnd, hdc);
				}
				break;
				default:
					break;
				}


			}
		}
	}

	//--------------------------------------
	//gdi plus �����ڵ� 
	GdiplusShutdown(gdiplusToken);
	//--------------------------------------


}

int getMapBlockAttr(int mx, int my)
{
	return g_MapAttrBlock[my * 8 + mx];
}

void eventKeyDown(WPARAM wParam) 
{
	int savePosX = g_nPlayerXPos;
	int savePosY = g_nPlayerYPos;

	switch (wParam)
	{
	case VK_UP:
	{
		g_nPlayerYPos--;
	}
		break;
	case VK_DOWN:
	{
		g_nPlayerYPos++;
	}
	break;
	case VK_LEFT:
	{
		g_nPlayerXPos--;
	}
	break;
	case VK_RIGHT:
	{
		g_nPlayerXPos++;
	}
	break;
	default:
		break;
	}
	if (getMapBlockAttr(g_nPlayerXPos, g_nPlayerYPos) == 1) {
		g_nPlayerXPos = savePosX;
		g_nPlayerYPos = savePosY;
	}
}