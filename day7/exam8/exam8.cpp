// exam8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//


#include "stdafx.h"

void dumpBuf(int nBuf[],int nSize) {
	for (int i = 0; i < nSize; i++) {
		printf("%d", nBuf[i]);
	}
	printf("\n");
}


int main()
{
	int nBuf[8] = { 1,2,3,4,5,6,7,8};
	dumpBuf(nBuf,sizeof(nBuf)/sizeof(nBuf[0]));
	bool bLoop = true;
	while (bLoop) {
		int nIndex = 0, nValue = 0;
		int nArySize = sizeof(nBuf) / sizeof(nBuf[0]);
		printf("������ ��ġ�� ���� �Է��ϼ��� : ");
		scanf("%d", &nIndex);

		if (nIndex > 15) {
			bLoop = false;
		}

		for (int i = nIndex ; i < nArySize; i++) {
			nBuf[i-1] = nBuf[i];
		}

		
		dumpBuf(nBuf, sizeof(nBuf) / sizeof(nBuf[0]));
	}

	return 0;
}


