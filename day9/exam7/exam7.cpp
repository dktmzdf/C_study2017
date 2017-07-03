// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	printf("주소값을 출력 : %u \n","Hello");
	printf("주소값을 출력 : %c \n", *"Hello");
	printf("주소값을 출력 : %c \n", "Hello"[0]);
	char *pStr = "Hello world";//문자열 상수는 임의로 바꿀수가 없음
	printf("주소값을 출력 : %u \n", pStr);
	printf("주소값을 출력 : %c \n", pStr[0]);
	pStr = pStr + 6;
	for (int i = 0; pStr[i] != 0x00; i++) {
		printf("%c",*(pStr + i));
	}
	printf("\n");
	pStr = pStr - 6;

	int i;
	char szBuf[256];
	for (i = 0; pStr[i] != 0x00; i++) {
		szBuf[i] = pStr[i];
	}
	szBuf[i] = 0x00;
	pStr = szBuf;

	for (int i = 0; pStr[i] != 0x00; i++) {
		if (*(pStr + i) == 'r') {
			*(pStr + i) = 'l';
		}
		else if (*(pStr + i) == 'l') {
			*(pStr + i) = 'r';
		}
		/*switch (pStr[i])
		{
		case 'l':
			pStr[i] = 'r';
			break;
		case 'r':
			pStr[i] = 'l';
			break;
		default:
			break;
		}*/
	}
	printf("주소값을 출력 : %s \n", pStr);
	printf("\n");
    return 0;
}

