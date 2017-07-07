// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

