// exam2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	printf("��� �� : %.2f\n",avg);
    return 0;
}

