// exam3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 10,20,30,40,50 };
	int *ap = ary;//�迭���� ������ �迭�� ù��° ���� ����Ŵ
	printf("%d \n", *(ary +1));

	printf("%d \n", *(ary+1));

	ap += 1;

	printf("%d \n", *(ary + 1));
	//ary = ary + 1;<- ���Ⱑ �ȵ�; 
    return 0;
}

