// exam5.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <Windows.h>

int main()
{
	BYTE Buffer[1024];//unsigned char��

	void *pVoid;

	Buffer[1024];

	pVoid = Buffer;
	printf("%d \n", pVoid);
	printf("%d \n", (BYTE *)pVoid+1);
	printf("%d \n", (double *)pVoid + 1);
	printf("%d \n", (int *)pVoid + 1);
	printf("%d \n", (char *)pVoid + 1);

	int a = 3;
	int b = 4;
	char *pMsg = "hello";
	
	memcpy((BYTE *)pVoid , &a, 4);
	memcpy((BYTE *)pVoid + 4, &b, 4);
	memcpy((BYTE *)pVoid + 8 , &pMsg, 4);

	
	printf("%d %d\n", *((int *)(BYTE *)pVoid), *(int *)(BYTE *)pVoid + 4);
	printf("%s \n", *(char **)((BYTE *)pVoid + 8));
	//void *aappa = (void *)malloc(sizeof(char) * 1024);
    return 0;
}

