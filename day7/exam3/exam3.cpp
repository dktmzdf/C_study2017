// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = {2,3,4,7,8,4,2,1,5,4,6,7,7,6,5,4};
	int num=0;
	printf("값을 입력하세요 : ");
	scanf("%d", &num);
	int nCount = 0;
	for (int i=0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		if (num == ary[i]) {
			nCount++;
		}

	}
	printf("%d",nCount);
    return 0;
}

