// exam12.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char strTemp[5];// = "Hani";
	
	//strTemp = "Hani"; \0,0x00
	
	strTemp[0] = 'H';
	strTemp[1] = 'a';
	strTemp[2] = 'n';
	strTemp[3] = 'i';
	strTemp[4] = 0x00;//�Ǵ� \0
	printf("%s\n", strTemp);

	char szBuf[256];
	printf("����� �̸��� �����Դϱ�? : ");
	scanf_s("%s",szBuf,sizeof(szBuf));

	printf("����� �̸��� :%s",szBuf);
	return 0;
}

