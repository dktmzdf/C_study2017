// exam1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char word[50];
	word[0] = 'L';
	word[1] = 'o';
	word[2] = 'v';
	word[3] = 'e';
	word[4] = '\0';
	printf("%s\n", word);

	//word[0] = '��';
	//word[1] = '��';
	//	printf("%s", word);

	TCHAR word2[50];
	word2[0] = L'��';
	word2[1] = L'��';
	word2[2] = L'\0';
	word2[3] = L'a';
	printf("char size: %d TCHAR size: %d", sizeof(char), sizeof(TCHAR));

	return 0;
}
