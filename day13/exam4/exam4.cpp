// exam4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int sum_int(void *pA, void *pB,void *pResult) 
{
	int a = *(int *)pA;
	int b = *(int *)pB;
}
int sum_double(void *pA, void *pB, void *pResult)
{
	double a = *(double *)pA;
	double b = *(double *)pB;
}
int main()
{
	void(*fpSum)(void *,void *);

    return 0;
}

