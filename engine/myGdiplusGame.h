#pragma once

namespace myGdiplusGame {

	const int g_nTileSize = 16;
	const int g_nTileXCount = 8;

	void drawTile(Graphics *pGrp, Image *pImgBasicTile, int nPosX, int nPosY, int *pTileLib)
	{
		int nTileIndex = pTileLib[nPosX + nPosY * g_nTileXCount];
		//int nTileIndex = 14;
		pGrp->DrawImage(pImgBasicTile,
			Rect(nPosX * 16, nPosY * 16, g_nTileSize, g_nTileSize),
			g_nTileSize * (nTileIndex % g_nTileXCount), //원본 x 위치
			g_nTileSize * (nTileIndex / g_nTileXCount),  //원본 y 위치
			g_nTileSize, g_nTileSize,
			UnitPixel);
	}

}