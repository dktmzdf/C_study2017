// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//32bit (4바이트) 메모리 공간 확보
	int num;
	int num2 = 168;
	static int e1;
	num = 10;
	printf("%d \n",num + 20);

	num = 20;
	printf("%d \n", num + 20);

	printf("%d \n", num2 + 20);
	printf("%d \n", e1 + 5);
	scanf("%d", &num);
    return 0;
}

