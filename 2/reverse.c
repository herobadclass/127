#include <stdio.h>
#include <math.h>

void reverse( int arr[], unsigned int len )
{
	for(int i = 0; i < floor(len/2); i++)
	{
		int hold = arr[i];
		arr[i] = arr[len-1-i];
		arr[len-1-i] = hold;
	}
}
