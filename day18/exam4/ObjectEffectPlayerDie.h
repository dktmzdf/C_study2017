#pragma once

struct S_ObjectEffectPlayerDie
{
	irr::core::vector2df m_vPosition;

	irr::f32 m_fLifeTime;
	int m_nFSM;

};

extern void ObjectEffectPlayerDie_Setup(S_ObjectEffectPlayerDie *pThis, irr::core::vector2df &vPos);
extern void ObjectEffectPlayerDie_OnRender(S_ObjectEffectPlayerDie *pThis, Graphics *pGrp);
extern void ObjectEffectPlayerDie_OnApply(S_ObjectEffectPlayerDie *pThis, double fDelta);
