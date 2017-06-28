// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

