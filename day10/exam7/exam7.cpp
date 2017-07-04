// exam7.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char szBuf[256];

	gets_s(szBuf,64);
	puts(szBuf);

    return 0;
}

