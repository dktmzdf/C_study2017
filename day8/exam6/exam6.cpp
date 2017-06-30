// exam6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{	
	int test1 = 100;
	int *pTest1;

	pTest1 = &test1;

	printf("%ld, %d \n", pTest1, *pTest1);

	test1 = 200;
	//*pTest1 = 200;
	
	//* ->참조 연산자 ,& -> 주소 연산자
	printf("%ld, %d \n", pTest1, *pTest1);
	printf("%ld, %d \n", pTest1, &test1);
	printf("%d, %d \n", sizeof(test1), sizeof(pTest1));

	int a;
	int *ap = &a;
	//int *ap;
	//ap=&a;
	a = 100;
	int b1 = 1;
	int b2 = b1;
	printf("%d, %d \n", a, ap);
	*&a = *&b1;//b의 주소를 참조해서 얻은 값을 a를 참조해서 얻은 주소에 가서 복사 
			   // a를 참조하는 주소로가서 얻은 곳 = b를 참조하는 주소로가서 얻은 값
	printf("%d, %d \n", &a, &b1);
	
	printf("%d, %d \n", b1,b2);
	b2 = 2;
	printf("%d, %d \n", b1, b2);
	*&b1 = *&b2;
	printf("%d, %d \n", b1, b2);
	b2 = 3;
	printf("%d, %d \n", b1, b2);
	/*
	int i = 0;
	char ch[] = { '-','/','|','\\','|' };
	while (1) {
		if (i == 5) i = 0;
		printf("\r %c", ch[i]);
		i++;
	}
	*/
    return 0;
}

