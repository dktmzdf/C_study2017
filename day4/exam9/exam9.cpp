// exam9.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	double pi = 3.14;
	printf("%lf \n", pi);
	double tax;

	printf("������ �Է��ϼ��� : ");
	scanf_s("%lf", &tax);
	printf("������ %lf%% �Դϴ� \n", tax);

	float test;
	printf("�ƹ� �Ǽ��� �Է��ϼ��� : ");
	scanf_s("%f", &test);
	printf("%f \n",test);
    return 0;
}

