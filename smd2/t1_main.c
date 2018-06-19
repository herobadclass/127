#include <stdio.h>
#include "t1.c"

int main()
{
	int a[5] = {0,1,2,4,3};
	int b[5] = {0,1,2,3,4};
	int c = identical(a,b,0);
	if(c == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}
