// exam8.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nNum = 0x11223344;
	unsigned char *pTest;//모든 포인터 변수의 크기는 4바이트
	
	pTest = (unsigned char *)&nNum;
	//pTest++;//0x22
	//pTest++;//0x33
	//pTest++;//0x44

	for (int i = 0; i < 4; i++) 
	{
		printf("%x\n",*(pTest+i));
	}
	nNum = 0;
	*pTest = 11;
	/*
	*(pTest + 0) = 1;
	*(pTest + 1) = 11;
	*(pTest + 2) = 21;
	*(pTest + 3) = 31;*/ // *(pTest + 1)는 주소를 1만큼 변경

	printf("nNum : %x \n", nNum);
    return 0;
}

