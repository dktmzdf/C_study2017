// exam10.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char aryChar[5] = { 10,20,30,40 };
	int intChar[5] = { 10,20,30,40 };

	char *ptrChar = aryChar;
	int *ptrint = intChar;



	for (int i = 0; i < 5; i++) {
		printf("%u %u \n", (ptrChar + i),(ptrint + i));//포인터에 대한 덧셈은 주소를 바꾸는 것인데 자료형만큼 주소가 움직임

	}

    return 0;
}

