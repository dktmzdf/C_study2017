#pragma once


extern void OnCreate(HWND hWnd);
//extern void OnDestory(HWND hWnd);
extern void OnDestory();
extern S_ObjectPlayer g_objPlayer;
extern BYTE g_KeyStatus[256];

extern int AddEffectBulletDie(irr::core::vector2df pos);
extern int AddEffectPlayerDie(irr::core::vector2df pos);