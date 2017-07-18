#include "stdafx.h"

HWND g_hWnd;

#define MAX_BULLET_LIST 252
#define MAX_MISSILE_LIST 2
#define MAX_EFFECT_BULLETDIE_LIST 256

BYTE g_KeyStatus[256];
S_ObjectPlayer g_objPlayer;
S_ObjectBullet *g_pBullet_List[MAX_BULLET_LIST];
S_ObjectMissile *g_pMissile_List[MAX_MISSILE_LIST];
S_ObjectEffectBulletDie *g_pEffectBulletDie_List[MAX_EFFECT_BULLETDIE_LIST];
S_ObjectEffectPlayerDie *g_pDestoryPlayer;

double g_fTimer = 0;
double g_fReload = 0.3;
int g_nMissleLimit = 0;
int g_nCurrentMissle = 0;
bool g_bCount = TRUE;

irr::core::vector2df g_vLunchBullet[8] = {
	irr::core::vector2df(0, -480),
	irr::core::vector2df(0, 480),
	irr::core::vector2df(640, 0),
	irr::core::vector2df(-640, 0),
	irr::core::vector2df(640, 480),
	irr::core::vector2df(640, -480),
	irr::core::vector2df(-640, 480),
	irr::core::vector2df(-640, -480),
};

Image *g_pImgSpaceShip;
Image *g_pImgSpaceShipDead;
Image *g_pImgBullet;
Image *g_pImgMissile;
Image *g_pBackGround;


irr::f64 g_fAcctick = 0;

// -1 : 생성 실패
//총알
int AddBullet()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_List[i] == NULL) {
			S_ObjectBullet *ptr = (S_ObjectBullet *)malloc(sizeof(S_ObjectBullet));
			ObjectBullet_Setup(ptr, g_vLunchBullet[rand()%8], g_objPlayer.m_vPosition, 8, rand() % 50 + 50, g_pImgBullet);
			g_pBullet_List[i] = ptr;
			return i;
		}
	}

	return -1;
}
//미사일
int AddMissile()
{
	
	if (g_nCurrentMissle < g_nMissleLimit) {
		for (int i = 0; i < MAX_MISSILE_LIST; i++) {
			if (g_pMissile_List[i] == NULL) {
				S_ObjectMissile *ptr = (S_ObjectMissile *)malloc(sizeof(S_ObjectMissile));
				ObjectMissile_Setup(ptr, g_vLunchBullet[rand() % 8], g_objPlayer.m_vPosition, 8, 400, g_pImgMissile);
				g_pMissile_List[i] = ptr;
				g_nCurrentMissle++;
				return i;
			}
		}
	}

	return -1;
}
//플레이어 사망처리
int AddEffectPlayerDie(irr::core::vector2df pos) {
	g_objPlayer.m_nFSM = 999;
	g_pDestoryPlayer = (S_ObjectEffectPlayerDie *)malloc(sizeof(S_ObjectEffectPlayerDie));
	ObjectEffectPlayerDie_Setup(g_pDestoryPlayer, pos,g_pImgSpaceShipDead);
	return 0;
}

int AddEffectBulletDie(irr::core::vector2df pos)
{
	int i;
	for (i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		if (g_pEffectBulletDie_List[i] == NULL) {
			S_ObjectEffectBulletDie *ptrB = (S_ObjectEffectBulletDie *)malloc(sizeof(S_ObjectEffectBulletDie));
			
			ObjectEffectBulletDie_Setup(ptrB, pos);
			
			
			g_pEffectBulletDie_List[i] = ptrB;
			return i;
		}
	}
	return -1;
}

void ClearDeadPlayerObj()
{
	if (g_pDestoryPlayer != NULL &&g_pDestoryPlayer->m_nFSM == 999) {
		free(g_pDestoryPlayer);
		g_pDestoryPlayer = NULL;
	}
}

void ClearDeadBulletObj()
{
	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {

		if (g_pBullet_List[i] != NULL && g_pBullet_List[i]->m_nFSM == 999) {
			free(g_pBullet_List[i]);
			g_pBullet_List[i] = NULL;
		}
	}
}

void ClearDeadMissileObj()
{
	int i;
	for (i = 0; i < MAX_MISSILE_LIST; i++) {

		if (g_pMissile_List[i] != NULL && g_pMissile_List[i]->m_nFSM == 999) {
			free(g_pMissile_List[i]);
			g_pMissile_List[i] = NULL;
			g_nCurrentMissle--;
		}
	}
}

void ClearDeadEffectBulletDieObj()
{
	int i;
	for (i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {

		if (g_pEffectBulletDie_List[i] != NULL && g_pEffectBulletDie_List[i]->m_nFSM == 999) {
			free(g_pEffectBulletDie_List[i]);
			g_pEffectBulletDie_List[i] = NULL;
		}
	}
}


void OnLoop(double fDelta)
{
	if (fDelta < 0 || fDelta > 1.0) {
		fDelta = 0;
	}

	//시체처리
	ClearDeadPlayerObj();
	ClearDeadBulletObj();
	ClearDeadMissileObj();
	ClearDeadEffectBulletDieObj();
	//타이머 관리

	if (((int)g_fTimer % 5) == 0) 
	{
		if (g_fReload > 0.24 && g_bCount ==TRUE) 
		{
			g_fReload -= 0.05;
			g_nMissleLimit++;
			g_bCount = FALSE;
		}
		
	}
	else {
		g_bCount = TRUE;
	}
	//총알 발사
	g_fAcctick += fDelta;
	if (g_fAcctick > g_fReload) {
		g_fAcctick = 0.0;
		AddBullet();
		AddMissile();
	}
	//플레이어 처리
	S_ObjectPlayer_OnApply(&g_objPlayer, fDelta);
	
	//총알 처리
	for (int i = 0; i < MAX_BULLET_LIST; i++) {

		S_ObjectBullet *ptr = g_pBullet_List[i];
		if (ptr != NULL) {
			ObjectBullet_OnApply(ptr, fDelta);
		}
	}
	for (int i = 0; i < MAX_MISSILE_LIST; i++) {

		S_ObjectMissile *ptr = g_pMissile_List[i];
		if (ptr != NULL) {
			ObjectMissile_OnApply(ptr, fDelta);
		}
	}

	//파괴 효과
	for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {

		S_ObjectEffectBulletDie *ptr = g_pEffectBulletDie_List[i];
		if (ptr != NULL) {
			ObjectEffectBulletDie_OnApply(ptr, fDelta);
		}
	}
	if (g_pDestoryPlayer != NULL &&g_objPlayer.m_nFSM == 999)
	{
		ObjectEffectPlayerDie_OnApply(g_pDestoryPlayer, fDelta);
	}
	
}

void OnRender(double fDelta, Graphics *pGrp)
{
	//초기화 및 설정
	pGrp->Clear(Color(200, 191, 231));
	Pen pen(Color(0, 0, 0));

	//배경
	pGrp->DrawRectangle(&pen, 0, 0, 640, 480);
	pGrp->DrawImage(g_pBackGround, RectF(0, 10, 640, 470));

	
	

	Matrix originMat(1, 0, 0, 1, 320, 240);
	pGrp->SetTransform(&originMat);
	if (g_objPlayer.m_nFSM != 999) {
		S_ObjectPlayer_OnRender(&g_objPlayer, pGrp);
	}

	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		S_ObjectBullet *ptrB = g_pBullet_List[i];
		if (ptrB != NULL) {
			ObjectBullet_OnRender(ptrB, pGrp);
		}
	}
	for (int i = 0; i < MAX_MISSILE_LIST; i++) {
		S_ObjectMissile *ptrP = g_pMissile_List[i];
		if (ptrP != NULL) {
			ObjectMissile_OnRender(ptrP, pGrp);
		}
	}
	//파괴 효과
	for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {

		S_ObjectEffectBulletDie *ptr = g_pEffectBulletDie_List[i];
		if (ptr != NULL) {
			ObjectEffectBulletDie_OnRender(ptr, pGrp);
		}
	}
	if (g_pDestoryPlayer != NULL &&g_objPlayer.m_nFSM == 999)
	{
		ObjectEffectPlayerDie_OnRender(g_pDestoryPlayer,pGrp);
	}

	
	pGrp->ResetTransform();
	//글
	if (fDelta > 0) {
		if (g_objPlayer.m_nFSM != 999) g_fTimer += fDelta;
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1.0 / fDelta);
		plusEngine::printf(pGrp, 120, 0, L"timer : %lf", g_fTimer);
		//plusEngine::printf(pGrp, 240, 0, L"score : %ld", g_nScore);
	}
	else {
		plusEngine::printf(pGrp, 0, 0, L"fps : %lf", 1000.f);
		plusEngine::printf(pGrp, 120, 0, L"timer : %lf", g_fTimer + fDelta);
		//plusEngine::printf(pGrp, 240, 0, L"score : %ld", g_nScore);
	}
	TCHAR szBuf[256];
	swprintf_s(szBuf,L"%lf %lf",(float)g_objPlayer.m_vPosition.X, (float)g_objPlayer.m_vPosition.Y);
	OutputDebugString(szBuf);
}

void OnCreate(HWND hWnd)
{
	g_hWnd = hWnd;
	plusEngine::fpOnLoop = OnLoop;
	plusEngine::fpOnRender = OnRender;
	//키상태 초기화 
	for (int i = 0; i < 256; i++) {
		g_KeyStatus[i] = 0;
	}

	for (int i = 0; i < MAX_BULLET_LIST; i++) {
		g_pBullet_List[i] = NULL;
	}
	for (int i = 0; i < MAX_MISSILE_LIST; i++) {
		g_pMissile_List[i] = NULL;
	}
	for (int i = 0; i < MAX_EFFECT_BULLETDIE_LIST; i++) {
		g_pEffectBulletDie_List[i] = NULL;
	}

	g_pImgSpaceShip = new Image(L"../../res/spaceship_crop.png");
	g_pImgSpaceShipDead = new Image(L"../../res/dead.png");
	g_pImgBullet = new Image(L"../../res/bullet_crop.png");
	g_pImgMissile = new Image(L"../../res/missile.png");
	g_pBackGround = new Image(L"../../res/background.png");


	S_ObjectPlayer_Setup(&g_objPlayer, irr::core::vector2df(0, 0), g_pImgSpaceShip);
	

}

void OnDestory()
{
	delete g_pImgSpaceShip;

	int i;
	for (i = 0; i < MAX_BULLET_LIST; i++) {
		if (g_pBullet_List[i] != NULL) {
			free(g_pBullet_List[i]);
		}
	}
}