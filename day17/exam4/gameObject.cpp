#include "stdafx.h"


void GameObject_Apply(GameObject *pThis,irr::f64 fDelta) 
{

}
void GameObject_Draw(GameObject *pThis,Graphics &grp)
{
	grp.DrawImage(pThis->m_pImg,
		pThis->m_vPosition.X, pThis->m_vPosition.Y ,
		pThis->m_pImg->GetWidth(), pThis->m_pImg->GetHeight());
}
