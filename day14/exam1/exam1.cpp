// exam1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>

int main()
{
	
	int *pA;
	
//	pA = (int *)malloc(sizeof(int)*1024);
	//int a = 7;
	//pA = &a;
	pA = (int *)malloc(4);

	*pA = 7;

	printf("%u \n",*pA);

	free(pA);

    return 0;
}

