// exam2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char *pTest = "123456789";
	char pTest2[32];

	char *ptr1 = pTest;
	printf("%s \n" ,ptr1);
	ptr1 += 1;
	printf("%s \n", ptr1);

	ptr1 += 5;
	printf("%s \n", ptr1);

	ptr1[0] = '*';
	printf("%s \n", pTest);
    return 0;
}

