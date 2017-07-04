// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<locale.h>
#include <string.h>

int main()
{//문자열 복사
	char *pTest = "apple";

	char pTemp[64];

	
	strcpy(pTemp,pTest);
	printf("%s \n",pTemp);
	strcpy(pTemp, pTest);
	printf("%s \n", pTemp+1);
	//유니코드 버전
	TCHAR *pwTest = L"먹다버린 사과";
	TCHAR szwBuf[64];

	wcscpy(szwBuf, pwTest);
	wcscpy(szwBuf, pwTest+4);//실제론 2칸 뒤로감
	wprintf(L"%wS \n", pwTest);
	//문자열 크기 구하기
	printf("%d \n",strlen(pTest));
	printf("%d \n", wcslen(pwTest));

	//문자열 비교sss
	printf("%d \n", wcslen(pwTest));
	//strcmp();
    return 0;
}

