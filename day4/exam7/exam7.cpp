// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	//32bit (4����Ʈ) �޸� ���� Ȯ��
	int num;
	int num2 = 168;
	static int e1;
	num = 10;
	printf("%d \n",num + 20);

	num = 20;
	printf("%d \n", num + 20);

	printf("%d \n", num2 + 20);
	printf("%d \n", e1 + 5);
	scanf("%d", &num);
    return 0;
}

