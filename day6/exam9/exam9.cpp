// exam9.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int i=0;
	while (1) {
		i++;
		if (i > 10) {
			break;
		}
		printf_s("%d \n",i);
	}
	printf_s("-------------------------------------\n");
	i = 0;
	while (1) {
		i++;
		if (i > 10) {
			break;
		}
		if (i % 2) {
			continue;
		}
		printf_s("%d \n", i);
	}
    return 0;
}

