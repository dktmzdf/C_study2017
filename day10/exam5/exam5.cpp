// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	TCHAR *wsTest = L"먹다버린 사관";
	TCHAR wszBuf[32];
	strcpy(szBuf, pTest);

	printf("$d\n",wcscmp(wsTest,wszBuf));
    return 0;
}

