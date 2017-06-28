// exam6.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a, b, c;
	a = 1;
	b = 1;
	c = 1;
	printf_s("%d,%d,%d \n", a++, a++, a++);//결과는 3,2,1 이유는 C는 함수 호출하면서 스택을 쌓는데 넘겨주는 인자를 스택에  
										//저장  그리고 쓸때 스택에서 뽑아씀 그리고 더하는건 먼저 함수에서 쓴 뒤에 더함
										//
										// a b c -> 1 2 3 a/++-> use a next plus
	printf_s("%d\n", a++);
	a = 1;
	printf_s("%d,%d,%d \n", ++a, ++a, ++a);
	printf_s("%d\n", a);

    return 0;
}

