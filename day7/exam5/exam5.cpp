// exam5.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int ary[2] = { 3,4 };
	int temp;
	temp = ary[0];
	ary[0] = ary[1];
	ary[1] = temp;

	printf("%d %d", ary[0], ary[1]);
	return 0;
}

