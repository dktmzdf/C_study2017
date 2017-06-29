// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = { 2,3,4,7,8,4,2,1,5,4,6,7,7,6,5,4 };
	int count[20] = { 0, };

	int num = 0;
	
	for (int i = 0; i < sizeof(count) / sizeof(ary[0]); i++) {
		for (int j = 0; j < sizeof(ary) / sizeof(ary[0]); j++) {
			if (i == ary[j]) {
				count[i]++;
			}
		}
		printf("%d -> %d \n",i, count[i]);
	}
	
	return 0;
}

