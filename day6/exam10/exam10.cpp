// exam10.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int printSum(int a, int b) {
	int sum = a + b;
	
	return sum;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = printSum(a ,b);
	printf("%d \n", sum);
    return 0;
}

