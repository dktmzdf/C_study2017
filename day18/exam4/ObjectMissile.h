#pragma once
struct S_ObjectMissile
{
	irr::core::vector2df m_vPosition;
	irr::core::vector2df m_vDirection;
	irr::f64 m_fVelocity;
	irr::f64 m_fSize;
	int m_nFSM;
	double m_flifeTime;

	Image *m_pImg;
};

extern void ObjectMissile_Setup(S_ObjectMissile *pThis, irr::core::vector2df &vStartPos,
	irr::core::vector2df &vTaegetPos,
	irr::f64 fVolumeSize,
	irr::f64 fVelocity,
	Image *pImg
);
extern void ObjectMissile_OnRender(S_ObjectMissile *pThis, Graphics *pGrp);
extern void ObjectMissile_OnApply(S_ObjectMissile *pThis, double fDelta);