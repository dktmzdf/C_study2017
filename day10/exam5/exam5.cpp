// exam5.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	char *pTest = "aple";
	char szBuf[32];

	
	printf("%d \,", strcmp(pTest,szBuf));
	strcpy(szBuf,pTest);

	printf("%d \,", strcmp(pTest,szBuf));

	szBuf['f'];
	printf("%d %s\m",szBuf,strcmp(szBuf,pTest));
	TCHAR *wsTest = L"�Դٹ��� ���";
	TCHAR wszBuf[32];
	strcpy(szBuf, pTest);

	printf("$d\n",wcscmp(wsTest,wszBuf));
    return 0;
}

