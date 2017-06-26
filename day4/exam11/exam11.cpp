// exam11.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num, age;
	float al;
	printf("등번호를 입력하세요. : ");
	scanf_s("%d",&num);
	printf("타율을 입력하세요. : ");
	scanf_s("%f",&al);
	printf("나이를 입력하세요. : ");
	scanf_s("%d",&age);
	
	printf("%d번 선수의 타율은 %f 이고 나이는 %d입니다.",num,al,age);
    return 0;
}

