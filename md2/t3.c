//t3.c
#include <stdio.h>
int repeat(int a[], unsigned int len)
{
	int range[401] = {0};
	for(int i = 0; i < len; i ++)
	{
		range[a[i]+200] = range[a[i]+200] + 1;
	}
	for(int i = 0; i < 401; i ++)
	{
		if(range[i] > 1)
		{
			return 1;
		}
	}
	return 0;
}
