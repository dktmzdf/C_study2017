// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	printf("�ּҰ��� ��� : %u \n","Hello");
	printf("�ּҰ��� ��� : %c \n", *"Hello");
	printf("�ּҰ��� ��� : %c \n", "Hello"[0]);
	char *pStr = "Hello world";//���ڿ� ����� ���Ƿ� �ٲܼ��� ����
	printf("�ּҰ��� ��� : %u \n", pStr);
	printf("�ּҰ��� ��� : %c \n", pStr[0]);
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
	printf("�ּҰ��� ��� : %s \n", pStr);
	printf("\n");
    return 0;
}

