// exam6.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int main()
{	
	int test1 = 100;
	int *pTest1;

	pTest1 = &test1;

	printf("%ld, %d \n", pTest1, *pTest1);

	test1 = 200;
	//*pTest1 = 200;
	
	//* ->���� ������ ,& -> �ּ� ������
	printf("%ld, %d \n", pTest1, *pTest1);
	printf("%ld, %d \n", pTest1, &test1);
	printf("%d, %d \n", sizeof(test1), sizeof(pTest1));

	int a;
	int *ap = &a;
	//int *ap;
	//ap=&a;
	a = 100;
	int b1 = 1;
	int b2 = b1;
	printf("%d, %d \n", a, ap);
	*&a = *&b1;//b�� �ּҸ� �����ؼ� ���� ���� a�� �����ؼ� ���� �ּҿ� ���� ���� 
			   // a�� �����ϴ� �ּҷΰ��� ���� �� = b�� �����ϴ� �ּҷΰ��� ���� ��
	printf("%d, %d \n", &a, &b1);
	
	printf("%d, %d \n", b1,b2);
	b2 = 2;
	printf("%d, %d \n", b1, b2);
	*&b1 = *&b2;
	printf("%d, %d \n", b1, b2);
	b2 = 3;
	printf("%d, %d \n", b1, b2);
	/*
	int i = 0;
	char ch[] = { '-','/','|','\\','|' };
	while (1) {
		if (i == 5) i = 0;
		printf("\r %c", ch[i]);
		i++;
	}
	*/
    return 0;
}

