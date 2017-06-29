// exam6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nAry[10] = { 1,2,3,4,10 };
	int nAry2[10] = { 0, };
	int nTemp=0;
	for (int i = 0; i < sizeof(nAry2) / sizeof(nAry2[0]); i++) {

		if ((i + 1) == nAry[i]) {
			nAry2[i] = nAry[i];
		}
		if ((i + 1) != nAry[i]) {
			if (i < sizeof(nAry) / sizeof(nAry[0])) {
				if (nAry[i] != 0) {
					nTemp = nAry[i];
					nAry2[nTemp - 1] = nTemp;
					nAry2[i] = (i + 1);
				}
				else if (nAry[i] == 0) {
					nAry2[i] = (i + 1);
				}
			}
			else {
				nAry2[i] = (i + 1);
			}
			
		}

	}

	for (int i = 0; i < 5; i++) {
		int nIns = nAry2[i];

		nAry[4 + (i + 1)] = nAry[4 + 1];
		nAry[4 + i] = nIns;

	}
	for (int i = 0; i < sizeof(nAry2) / sizeof(nAry2[0]); i++) {
		printf("%d ", nAry2[i]);
	}
    return 0;
}

