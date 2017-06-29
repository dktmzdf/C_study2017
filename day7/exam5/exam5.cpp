// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[2] = { 3,4 };
	int temp;
	temp = ary[0];
	ary[0] = ary[1];
	ary[1] = temp;

	printf("%d %d", ary[0], ary[1]);
	return 0;
}

