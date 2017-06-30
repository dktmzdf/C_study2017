// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void assign(int *test)//포인터가 없으면 값을 복사함 (call of value) 포인터가 있으면 주소를 value로 복사함 (call of value)
//call of reference는 c에는 없다
{
	*test = 100;
}

void getSum(int a, int b, int *nSum)
{
	*nSum = a + b;
}

void exchange(int *a, int *b) {
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

int main()
{
	int test=0;

	assign(&test);//주소를 넘겨줌
	printf("%d \n", test);
	getSum(5, 6, &test);
	printf("%d \n",test);

	int a, b;
	a = 1;
	b = 7;
	exchange(&a,&b);
	printf("%d %d\n", a,b);
    return 0;
}

