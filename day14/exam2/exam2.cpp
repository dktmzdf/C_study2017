// exam2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>

void test1(int **pA) 
{
	//int a = 7;
	//*pA = &a;
	*pA = (int *)malloc(4);
	**pA = 7;
}

void test2(int **pA)
{

	int b = 3;
}

int main()
{
	int *pA;
	test1(&pA);

	printf("%d \n", *pA);
	test2(&pA);
	

	printf("%d \n",*pA);
	free(pA);

    return 0;
}

