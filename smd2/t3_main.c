#include <stdio.h>
#include "t3.c"

int main()
{
	int a[] = {0,1,2,0,4};
	int result = repeat(a,5);
	if(result == 0)
	{
		printf("no repeated numbers\n");
	}
	else if(result == 1)
	{
		printf("there are repeated numbers\n");
	}
	return 0;
}
