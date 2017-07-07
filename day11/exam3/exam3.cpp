// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

double getValue(double *aryValue) 
{
	static int a = 0;
	double nValue = aryValue[a];
	a++;

	return nValue;
}



int main()
{
	double fAry[] = {0.1,0.3,0.5,0.7,0.9};
	double nValue[5];
	for (int i = 0; i < 5; i++) {
		nValue[i] = getValue(fAry);
		printf("%.2f ", nValue[i]);
	}
	
    return 0;
}

