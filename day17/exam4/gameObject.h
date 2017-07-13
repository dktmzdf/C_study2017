#pragma once

struct GameObject
{
	irr::core::vector2df m_vPosition;
	irr::f64 m_fRotation;
	irr::f64 m_fSpeed;

	//irr::core::vector2df 

	Image *m_pImg;
};

extern void GameObject_Apply(GameObject *pThis, irr::f64 fDelta);
extern void GameObject_Draw(GameObject *pThis, Graphics &grp);