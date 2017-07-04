// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	char szBuf[256];

	//gets_s(szBuf,64);
	//puts(szBuf);

	char c;
	//c = getchar();
	//putchar(c);

	char szTemp[64] = "apple[seed]tree";
	int nBufSize =strlen(szTemp);
	int nTempSize1 = strlen("apple");
	int nTempSize2 = strlen("[seed]");
	/*for (int i = 0; szTemp[nTempSize1 + nTempSize2 + i] != 0x00; i++) {
		szTemp[nTempSize1 + i] = szTemp[nTempSize1 + nTempSize2 + i];
	}
	printf("%s\n",szTemp);*/
	
	strcpy((szTemp + nTempSize1), (szTemp + nTempSize1 + nTempSize2));
	printf("%s\n", szTemp);
	//////
	szTemp[5] = 0x00;
	strcat(szTemp, szTemp + 11);
	printf("%s \n",szTemp);
    return 0;
}

