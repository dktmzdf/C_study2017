// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int main()
{
	printf("�ּҰ��� ��� : %u \n", "hello");
	printf("�ּҰ��� ��� : %c \n", *"hello");
	printf("�ּҰ��� ��� : %c \n", "hello"[0]);

	char *pStr = "hello world";

	printf("�ּҰ��� ��� : %u \n", pStr);
	printf("�ּҰ��� ��� : %c \n", pStr[0]);

	pStr += 6;
	for (int i = 0; pStr[i] != 0x00; i++) {
		printf("%c", *(pStr + i));
	}

	printf("\n");

	pStr -= 6;

	int i = 0;
	char szBuf[256];
	for (i = 0; pStr[i] != 0x00; i++) {
		szBuf[i] = pStr[i];
	}
	szBuf[i] = 0x00;

	pStr = szBuf;

	for (int i = 0; pStr[i] != 0x00; i++) {
		switch (pStr[i]) {
		case 'l':
			pStr[i] = 'r';
			break;
		case 'r':
			pStr[i] = 'l';
			break;
		}
		//printf("%c", *(pStr + i));
	}
	printf("%s \n", pStr);

    return 0;
}

