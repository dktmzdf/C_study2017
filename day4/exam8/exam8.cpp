// exam8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	int num = 0;
	int num2;
	printf_s("�������� �Է��ϼ��� : ");
	scanf_s("%d,%d", &num,&num2);
	printf_s("%d, %d�� �Է��ϼ̽��ϴ�.\n", num,num2);
	printf_s("�� ���� ���� %d", num + num2);
    return 0;
}

