// exam5.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{

	//int test1:9����Ʈ����
	char test1;
	char test2;
	char test3;
	int test4;
	int test5;
	char test6;
	char test7;
	//char test8;

	test1 = 0x11;
	test2 = 0x22;
	test3 = 0x33;
	printf("test1 : %d\n", ((unsigned long)&test1) - ((unsigned long)&test2));
	printf("test1 : %d\n", ((unsigned long)&test2) - ((unsigned long)&test3));
	printf("test1 : %d\n", ((unsigned long)&test3) - ((unsigned long)&test4));
	printf("test1 : %d\n", ((unsigned long)&test4) - ((unsigned long)&test5));
	printf("test1 : %d\n", ((unsigned long)&test5) - ((unsigned long)&test6));
	printf("test1 : %d\n", ((unsigned long)&test6) - ((unsigned long)&test7));
	

    return 0;
}

