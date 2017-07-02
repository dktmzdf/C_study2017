// bubble.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void Bobble_sort(int *pArr, int size) { //������� �迭�� ũ��
	int fir, last, temp, i;
	for (fir = 0; fir < size; fir++) {
		for (last = 0; last < size - fir - 1; last++) {
			if (pArr[last + 1] < pArr[last]) {
				temp = pArr[last];
				pArr[last] = pArr[last + 1];
				pArr[last + 1] = temp;
			}
		}
	}
}

int main()
{
	const int nArySize = 5;
	int nAry[nArySize] = { 56,23,7,3421,76 };

	int i = 0;
	Bobble_sort(nAry,nArySize);
	for (i = 0; i < nArySize; i++) {
		printf("%d ",nAry[i]);
	}
	printf("\n");
    return 0;
}

