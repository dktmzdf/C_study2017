// exam1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ages[5];
	//ages[2] = 20;
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d ��° �����͸� �Է��ϼ���. : ",i);
		scanf("%d",&ages[i]);//�Ϸķ� �ᵵ��
	}

	int avg = 0;
	int min , max;
	for (i = 0; i < 5; i++) {
		avg += ages[i];
		if (i==0) {
			min = ages[0];
			max = ages[0];
		}
		if (min > ages[i]) {
			min = ages[i];
		}
		else if (max < ages[i]) {
			max = ages[i];
		}
	}

	avg = avg / 5;
	printf_s("��� : %d �ּ� : %d �ִ� : %d", avg, min, max);
    return 0;
}

