// exam4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int i = 0;
	int sum = 0;
	
	while (i <= 100) {
		if ((i % 2) == 1) {
			sum += i;
		}
		i++;
	}
	printf("%d",sum);
    return 0;
}

