// exam8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<stdlib.h>

int main()
{
	char *strItems = "pike,plate armor,lather armor,lather hemet,lather grove,sword,dager";

	int nIndexTable[32] = { 0, };

	int nIndex = 0, nCount = 0, i;
	printf("select index : ");
	scanf("%d", &nIndex);
	nIndex--;

	for (i = 0; strItems[i] != 0x00; i++)
	{
		if (strItems[i] == ',')
		{
			nIndexTable[++nCount] = i;
		}

	}
	char *pTemp = &(strItems[nIndexTable[nIndex]]);
	if (nIndex <nCount) 
	{
		char *pTemp = &(strItems[nIndexTable[nIndex]]);
		for (i = 0; i < nIndexTable[nIndex + 1] - nIndexTable[nIndex]; i++)
		{

			if (pTemp[i] != ',') printf("%c", pTemp[i]);
		}
	}
	if (nIndex == nCount) 
	{
		for (i = 0 ; pTemp[i] != 0x00; i++)
		{

			if (pTemp[i] != ',') printf("%c", pTemp[i]);
		}
	}

	/*
	char szBuf[256];
	for (i = 0; strItems[i] != 0x00; i++) {
		szBuf[i] = strItems[i];
	}
	szBuf[i] = 0x00;

	for (i = 0; szBuf[i] != 0x00; i++)
	{
		if (szBuf[i] == ',')
		{
			nIndexTable[nCount++] = i;
		}

	}
	for (i = 0; i < 32; i++)
	{
		printf("%d ", nIndexTable[i]);
	}
	if (nIndex == 1)
	{
		for (i = 0; i<nIndexTable[nIndex - 1]; i++)
		{
			printf("%c", szBuf[i]);
		}
	}
	else
	{
		for (i = nIndexTable[nIndex - 2] + 1; i < nIndexTable[nIndex - 1]; i++)
		{
			printf("%c", szBuf[i]);
		}
	}
	*/
	printf("\n");
	return 0;
}

