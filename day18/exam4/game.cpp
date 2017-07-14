#include "stdafx.h"

HWND g_hWnd;

#define MAX_BULLET_LIST 16
BYTE g_KeyStatus[256];
S_ObjectPlayer g_objPlayer;
S_ObjectBullet *g_pBullet_list[MAX_BULLET_LIST];

Image *g_pImgSpaceShip;
irr::f64 g_fAcctick = 0;

//-1 : 생성 실패
int AddBullet() {
	int i = 0;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_list[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, irr::core::vector2df(-160, -120), g_objPlayer.m_vPosition, 8, rand() % 100);
			g_pBullet_list[i] = ptr;
			return i;
		}
	}
	return -1;
}
//시체처리
void ClearDeadBulletObj() 
{
	
	int i = 0;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_list[i] != NULL && g_pBullet_list[i]->m_nFSM == 999) {
			free(g_pBullet_list[i]);
			g_pBullet_list[i] = NULL;
			break;
		}
	}
}


void OnLoop(double fDelta)
{
	if (fDelta < 0 || fDelta > 1.0) {
		fDelta = 0;
	}
	
	ClearDeadBulletObj();
	//총알 발사
	g_fAcctick += fDelta;
	if (g_fAcctick > 2.0) {
		g_fAcctick = 0.0;
		AddBullet();
	}

	//플레이어 처리
	S_ObjectPlayer_OnApply(&g_objPlayer, fDelta);
	
	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		
		S_ObjectBullet *ptr = g_pBullet_list[i];
		if (ptr != NULL) {
			ObjectBullet_OnApply(ptr, fDelta);
		}
	}
}

void OnRender(double fDelta, Graphics *pGrp)
{
	pGrp->Clear(Color(200, 191, 231));
	if (fDelta > 0) {
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1.0 / fDelta);
	}
	else {
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1000.f);
	}
	Pen pen(Color(0, 0, 0));
	//Pen pen2(Color(255, 0, 0));
	pGrp->DrawRectangle(&pen, 0, 0, 320, 240);
	pGrp->DrawLine(&pen, 0, 120, 320, 120);
	pGrp->DrawLine(&pen, 160, 0, 160, 240);

	Matrix originMat(1, 0, 0, 1, 160, 120);
	pGrp->SetTransform(&originMat);

	S_ObjectPlayer_OnRender(&g_objPlayer, pGrp);
	//ObjectBullet_OnRender(&g_TestBullet, pGrp);
	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		
		S_ObjectBullet *ptr = g_pBullet_list[i];
		if (ptr != NULL) {
			ObjectBullet_OnRender(ptr, pGrp);
		}
	}
	pGrp->ResetTransform();

}


void OnCreate(HWND hWnd)
{
	g_hWnd = hWnd;
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;

	for (int i = 0; i < 256; i++) {
		g_KeyStatus[i] = 0;
	}

	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		g_pBullet_list[i] = NULL;
		
	}
	g_pImgSpaceShip = new Image(L"../../res/spaceship_crop.png");

	S_ObjectPlayer_Setup(&g_objPlayer, irr::core::vector2df(0, 0), g_pImgSpaceShip);
	

}

void OnDestory(HWND hWnd)
{
	
	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_list[i] != NULL) g_pBullet_list[i] = NULL;
	}
	delete g_pImgSpaceShip;
	
}