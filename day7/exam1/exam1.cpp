// exam1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ages[5];
	//ages[2] = 20;
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d 번째 데이터를 입력하세요. : ",i);
		scanf("%d",&ages[i]);//일렬로 써도됨
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
	printf_s("평균 : %d 최소 : %d 최대 : %d", avg, min, max);
    return 0;
}

