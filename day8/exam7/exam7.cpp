// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void assign(int *test)//�����Ͱ� ������ ���� ������ (call of value) �����Ͱ� ������ �ּҸ� ������ (call of reference)
{
	*test = 100;
}

void getSum(int a, int b, int *nSum)
{
	*nSum = a + b;
}

void exchange(int *a, int *b) {
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int main()
{
	int test=0;

	assign(&test);//�ּҸ� �Ѱ���
	printf("%d \n", test);
	getSum(5, 6, &test);
	printf("%d \n",test);

	int a, b;
	a = 1;
	b = 7;
	exchange(&a,&b);
	printf("%d %d\n", a,b);
    return 0;
}

