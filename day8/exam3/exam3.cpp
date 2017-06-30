// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
int main()
{
	char szInputBuf[] = "24,45,67,100,45";
	char szTemp[16];//토큰 저장 버퍼

	int nTempIndex = 0;
	strtok(szInputBuf,",");
	//, 기준으로 끊어내기
	int nSum=0;
	int n_szInputBuf_Size = sizeof(szInputBuf)/sizeof(char);
	for (int i = 0; i < n_szInputBuf_Size+1; i++) 
	{
		if (szInputBuf[i] == ',' || szInputBuf[i] == '\0') {

			szTemp[nTempIndex] = NULL;
			printf("%s \n", szTemp);
			int nNum = atoi(szTemp);
			nSum += nNum;
			nTempIndex = 0;
		}
		else {
			szTemp[nTempIndex++] = szInputBuf[i];
		}
	}

	printf("sum %d", nSum);
    return 0;
}

