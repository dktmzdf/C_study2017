// exam9.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ary[5] = {12,20,30,40,50};
	int *pAry;

	pAry = ary;//���ȣ�� �����ϸ� �� ù��° �迭�� �ּҸ� �Ѱ���

	for (int i = 0; i < 5; i++) 
	{
		printf("%d %d %d %d \n",ary[i], *(ary+i), pAry[i] ,*(pAry+i));
	}

	//ary = pAry -> �ȵ� �迭�� read only��� ���� ��
	printf("%d \n", pAry[0]);

    return 0;
}

