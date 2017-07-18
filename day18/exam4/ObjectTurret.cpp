#include "stdafx.h"


struct S_ObjectTurret
{
	irr::core::vector2df m_vPosition;
	irr::core::vector2df m_vDirection;
	irr::core::vector2df m_vBullet_Direction;

	irr::f64 m_fVelocity;
	irr::f64 m_fSize;
	int m_nFSM;
	double m_flifeTime;

	Image *m_pImg;
};