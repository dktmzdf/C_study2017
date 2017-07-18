#include "stdafx.h"


void ObjectMissile_OnApply(S_ObjectMissile *pThis, double fDelta)
{
	pThis->m_flifeTime += fDelta;

	switch (pThis->m_nFSM)
	{
	case 0: // ready
		pThis->m_nFSM = 10;
		break;
	case 10: //go
	{
		
		irr::core::vector2df vDir(1, 0);

		irr::core::vector2df vRotation = g_objPlayer.m_vPosition - pThis->m_vPosition ;
	
		
		//vRotation.normalize();
		//irr::f64 fAngle = vRotation.getAngle();
		//pThis->m_vDirection.rotateBy(-fAngle);
		vRotation.normalize();
		pThis->m_vDirection += vRotation * 0.03;
		pThis->m_vDirection.normalize();
		
		pThis->m_vPosition += pThis->m_vDirection*(pThis->m_fVelocity*fDelta);
		

		irr::f64 fDist = (pThis->m_vPosition - g_objPlayer.m_vPosition).getLength();
		
		
		//�Ѿ�ũ�� + ����� ũ��
		if (fDist < (pThis->m_fSize + 1) && g_objPlayer.m_nFSM != 999) {
			AddEffectBulletDie(pThis->m_vPosition);
			AddEffectPlayerDie(g_objPlayer.m_vPosition);
			pThis->m_nFSM = 999;

		}
		//������Ÿ�� �˻� 
		if (pThis->m_flifeTime > 3) {

			pThis->m_nFSM = 999;
		}
	}
	break;
	default:
		break;
	}



}
void ObjectMissile_OnRender(S_ObjectMissile *pThis, Graphics *pGrp)
{
	Pen pen(Color(255, 0, 0));
	pGrp->DrawEllipse(&pen,
	(int)(pThis->m_vPosition.X - pThis->m_fSize / 2.0),
	(int)(pThis->m_vPosition.Y - pThis->m_fSize / 2.0),
	pThis->m_fSize, pThis->m_fSize
	);
	/*
	Matrix oldMat;
	pGrp->GetTransform(&oldMat);

	
	

	pGrp->RotateTransform(-(pThis->m_vDirection.getAngle()));
	pGrp->DrawImage(pThis->m_pImg, RectF(pThis->m_vPosition.X - 36 / 2, pThis->m_vPosition.Y - 16 / 2, 36, 16));

	pGrp->SetTransform(&oldMat);
	
	
	*/
	
}
void ObjectMissile_Setup(S_ObjectMissile *pThis, irr::core::vector2df &vStartPos,
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
	
	pThis->m_vDirection = (vTaegetPos - vStartPos);
	pThis->m_vDirection.normalize();
	pThis->m_flifeTime = 0;
	pThis->m_pImg = pImg;
}