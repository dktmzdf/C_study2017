#include "stdafx.h"

void ObjectBullet_OnApply(S_ObjectBullet *pThis, double fDelta)
{
	pThis->m_flifeTime += fDelta;

	switch (pThis->m_nFSM)
	{
	case 0: // ready
		pThis->m_nFSM = 10;
		break;
	case 10: //go
	{
		pThis->m_vPosition += pThis->m_vDirection*pThis->m_fVelocity*fDelta;

		irr::f64 fDist = (pThis->m_vPosition - g_objPlayer.m_vPosition).getLength();

		//총알크기 + 비행기 크기
		if (fDist < (pThis->m_fSize + 1) && g_objPlayer.m_nFSM != 999) {
			AddEffectBulletDie(pThis->m_vPosition);
			AddEffectPlayerDie(g_objPlayer.m_vPosition);
			pThis->m_nFSM = 999;
			
		}
		//라이프타임 검사 
		if (pThis->m_flifeTime > 25) {

			pThis->m_nFSM = 999;
		}
	}
	break;
	default:
		break;
	}



}
void ObjectBullet_OnRender(S_ObjectBullet *pThis, Graphics *pGrp)
{
	
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X - 29 / 2, pThis->m_vPosition.Y - 29 / 2, 29, 29));
//	pGrp->ScaleTransform(0.5, 0.5);
	//pGrp->ResetTransform();
}
void ObjectBullet_Setup(S_ObjectBullet *pThis, irr::core::vector2df &vStartPos,
	irr::core::vector2df &vTaegetPos,
	irr::f64 fVolumeSize,
	irr::f64 fVelocity,
	Image *pImg
)
{
	pThis->m_fSize = fVolumeSize;
	pThis->m_fVelocity = fVelocity;
	pThis->m_nFSM = 0; //ready
	pThis->m_vPosition = vStartPos;
	int nAcc= (rand() % 100);
	if(nAcc % 2 == 0) pThis->m_vDirection = (vTaegetPos - vStartPos) + nAcc;
	else if (nAcc % 2 != 0) pThis->m_vDirection = (vTaegetPos - vStartPos) - nAcc;
	pThis->m_vDirection.normalize();
	pThis->m_flifeTime = 0;
	pThis->m_pImg = pImg;
}