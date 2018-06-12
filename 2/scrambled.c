#include <stdio.h>

int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
{
	int rangeA[100] = {0};
	int rangeB[100] = {0};
	for(int i = 0; i < len; i++)
	{
		rangeA[a[i]] = rangeA[a[i]] + 1;
		rangeB[b[i]] = rangeB[b[i]] + 1;
	}
	for(int i = 0; i < 100; i++)
	{
		if(rangeA[i] != rangeB[i])
		{
			return 0;
		}
	}
	return 1;
}
