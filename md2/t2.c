// t2.c
#include <stdio.h>
#include <stdlib.h>
typedef enum{
	ZERO,
	ONE,
}binary_t;

binary_t *binary_and(binary_t *a, binary_t *b, unsigned int len)
{
	if(len == 0 || a == NULL || b == NULL)
	{
		return NULL;
	}
	binary_t *result = malloc(len*4*sizeof(char));
	if(result == NULL)
	{
		return NULL;
	}
	for(int i = 0; i < len; i ++)
	{
		if(a[i] == ONE && b[i] == ONE)
		{
			result[i] = ONE;
		}
		else
		{
			result[i] = ZERO;
		}
	}
	return result;
}
