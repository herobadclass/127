//t1.c
#include <stdio.h>
typedef struct{
	int* data;
	unsigned int len;
}intarr_t;

int intarr_min(intarr_t *ia, int* result)
{
	if(ia == NULL || ia->len == 0 || ia->data == NULL)
	{
		return -1;
	}
	int min = ia->data[0];
	for(int i = 0; i < ia->len; i ++)
	{
		if(ia->data[i] < min)
		{
			min = ia->data[i];
		}
	}
	*result = min;
	return 0;
}
