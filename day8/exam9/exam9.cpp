// exam9.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[5] = {12,20,30,40,50};
	int *pAry;

	pAry = ary;//대괄호를 생략하면 맨 첫번째 배열의 주소를 넘겨줌

	for (int i = 0; i < 5; i++) 
	{
		printf("%d %d %d %d \n",ary[i], *(ary+i), pAry[i] ,*(pAry+i));
	}

	//ary = pAry -> 안됨 배열은 read only라고 봐도 됨
	printf("%d \n", pAry[0]);

    return 0;
}

