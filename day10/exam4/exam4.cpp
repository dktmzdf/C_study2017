// exam4.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include<locale.h>
#include <string.h>

int main()
{//���ڿ� ����
	char *pTest = "apple";

	char pTemp[64];

	
	strcpy(pTemp,pTest);
	printf("%s \n",pTemp);
	strcpy(pTemp, pTest);
	printf("%s \n", pTemp+1);
	//�����ڵ� ����
	TCHAR *pwTest = L"�Դٹ��� ���";
	TCHAR szwBuf[64];

	wcscpy(szwBuf, pwTest);
	wcscpy(szwBuf, pwTest+4);//������ 2ĭ �ڷΰ�
	wprintf(L"%wS \n", pwTest);
	//���ڿ� ũ�� ���ϱ�
	printf("%d \n",strlen(pTest));
	printf("%d \n", wcslen(pwTest));

	//���ڿ� ��sss
	printf("%d \n", wcslen(pwTest));
	//strcmp();
    return 0;
}

