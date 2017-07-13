#pragma once

struct GameObject
{
	//0이면 준비 10 날아가기, 20 죽음
	int m_nFSM;
	irr::core::vector2df m_vPosition;
	irr::f64 m_fRotation;
	irr::f64 m_fSpeed;
	irr::f64 m_fFuel;

	//irr::core::vector2df 

	Image *m_pImg;
};

extern void GameObject_Apply(GameObject *pThis, irr::f64 fDelta);
extern void GameObject_Draw(GameObject *pThis, Graphics &grp);