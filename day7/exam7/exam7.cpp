// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void dumpBuf(int nBuf[]) {
	for (int i = 0; i < 16; i++) {
		printf("%d", nBuf[i]);
	}
	printf("\n");
}


int main()
{
	int nBuf[16] = {0,};
	dumpBuf(nBuf);
	bool bLoop = true;
	while (bLoop) {
		int nIndex = 0, nValue = 0;
		int nArySize = sizeof(nBuf) / sizeof(nBuf[0]);
		printf("������ ��ġ�� ���� �Է��ϼ���(�������) : ");
		scanf("%d %d",&nIndex, &nValue);

		if (nIndex > 15) {
			bLoop = false;
		}
		
		for (int i = nArySize-1; i > nIndex-1 ; i--) {
				nBuf[i] = nBuf[i - 1];	
		}
		
		nBuf[nIndex - 1] = nValue;
		dumpBuf(nBuf);
	}
	
	return 0;
}

