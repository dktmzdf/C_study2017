// exam10.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char aryChar[5] = { 10,20,30,40 };
	int intChar[5] = { 10,20,30,40 };

	char *ptrChar = aryChar;
	int *ptrint = intChar;



	for (int i = 0; i < 5; i++) {
		printf("%u %u \n", (ptrChar + i),(ptrint + i));//�����Ϳ� ���� ������ �ּҸ� �ٲٴ� ���ε� �ڷ�����ŭ �ּҰ� ������

	}

    return 0;
}

