#include <stdio.h>

int repeat(int a[], unsigned int len)
{
	int count[101] = {0};
	for(int i = 0; i < len; i++)
	{
		count[a[i]] = count[a[i]] + 1;
	}
	for(int i = 0; i < 101; i++)
	{
		if(count[i] > 1)
		{
			return 1;
		}
	}
	return 0;
}
