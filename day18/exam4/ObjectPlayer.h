#pragma once

struct S_ObjectPlayer {

	irr::core::vector2df m_vPosition;
	int m_nFSM;

	Image *m_pImg;
	Image *m_pDeadImg;

};


extern void S_ObjectPlayer_OnApply(S_ObjectPlayer *pThis, double fDelta);
extern void S_ObjectPlayer_OnRender(S_ObjectPlayer *pThis, Graphics *pGrp);
extern void S_ObjectPlayer_Setup(S_ObjectPlayer *pThis, irr::core::vector2df &startPos, Image *pImg);
extern void S_ObjectPlayer_OnDestory(S_ObjectPlayer *pThis);