// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double ary[] = { 1.5,20.1,16.4,2.3,3.5 };
	
	double avg, sum = 0;
	for(int i= 0;i < 5; i++)
	{
		sum += *(ary + i);
	}
	avg = sum / 5;
	printf("평균 값 : %.2f\n",avg);
    return 0;
}

