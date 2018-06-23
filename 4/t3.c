#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <string.h>
#include <math.h>
int fxy(int k,int edge)
{    
	if (k >= 0 && k < edge)
	{
		return k;
	}
	else if (k<0)
	{
		return edge-1;
	}
	else
	{
		return 0;
	}
}

void life( uint8_t array[], 
     unsigned int cols, 
     unsigned int rows )
{
	int count_array[rows*cols];
	for(int i = 0; i < rows*cols; i ++)
	{
		int count = 0;
		for (int m = -1; m < 2; m ++)
		{
			int x = fxy(i%cols+m,cols);
			for (int n = -1; n < 2; n ++)
			{
				int y = fxy(i/cols+n,rows);
				if(array[y*cols+x] == 255)
				{
					count ++;
				}
			}
		}
		count_array[i] = count;
		
	}
	for(int i = 0; i < rows*cols; i ++)
	{
		if(array[i] == 255)
		{
			if (count_array[i] != 3 && count_array[i] != 4)
			{
				array[i] = 0;
			}			
		}
		else 
		{
			if (count_array[i] == 3)
			{
				array[i] = 255;
			}
		}
	}
	
}
	