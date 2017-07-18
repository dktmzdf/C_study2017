#include "stdafx.h"

void ObjectEffectPlayerDie_OnApply(S_ObjectEffectPlayerDie *pThis, double fDelta)
{


	switch (pThis->m_nFSM)
	{
	case 0:
		pThis->m_nFSM = 10;

		break;
	case 10:
		pThis->m_fLifeTime += fDelta;
		if (pThis->m_fLifeTime > 3.0) {
			pThis->m_nFSM = 20;
		}
		break;
	case 20:
	{
		pThis->m_nFSM = 999;
		S_ObjectPlayer_OnDestory(&g_objPlayer);
	}
	break;
		
	}

}

void ObjectEffectPlayerDie_OnRender(S_ObjectEffectPlayerDie *pThis, Graphics *pGrp)
{
	/*/
	Pen pen(Color(0, 255, 0));
	Matrix tempMat;
	pGrp->GetTransform(&tempMat);
	pGrp->TranslateTransform(pThis->m_vPosition.X, pThis->m_vPosition.Y);
	pGrp->ScaleTransform(pThis->m_fLifeTime, pThis->m_fLifeTime);
	pGrp->DrawEllipse(&pen, -8, -8, 16, 16);
	pGrp->SetTransform(&tempMat);
	*/
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X - 29 / 2, pThis->m_vPosition.Y - 29 / 2, 29, 29));
}

void ObjectEffectPlayerDie_Setup(S_ObjectEffectPlayerDie *pThis, irr::core::vector2df &vPos, Image *pImg)
{
	pThis->m_vPosition = vPos;
	pThis->m_fLifeTime = 0;
	pThis->m_nFSM = 0;
	pThis->m_pImg = pImg;
}