// exam10.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

