// exam2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	double ary[] = { 1.5, 20.1, 16.4, 2.3, 3.5 };
	double *ap = ary;
	//ap = ary;
	double tot=0;

	for (int i = 0; i < 5; i++) {
		//tot += ary[i];
		//tot += *(ary + i);
		tot += *(ap + i);
		//tot += *(&ary[0]+i);
	}

	printf("%lf \n", tot / 5);

    return 0;
}

