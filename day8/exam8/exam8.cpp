// exam8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int nNum = 0x11223344;
	unsigned char *pTest;//��� ������ ������ ũ��� 4����Ʈ
	
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
	*(pTest + 3) = 31;*/ // *(pTest + 1)�� �ּҸ� 1��ŭ ����

	printf("nNum : %x \n", nNum);
    return 0;
}

