#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void draw_rectangle( uint8_t array[], 
                          unsigned int cols, 
                          unsigned int rows, 
                          int x,
                          int y,
                          int rect_width,
                          int rect_height,
                          uint8_t color )
{
	unsigned int uw = rect_width;
	unsigned int uh = rect_height;
	if(rect_height == 0 || rect_width == 0)
	{
		exit(0);
	}
	else
	{
		if(rect_width > 0 && rect_height > 0)
		{
			for(int i = 0; i < uw; i ++)
			{
				array[x+i+y*cols] = color;
				array[x+i+(y+uh-1)*cols] = color;
			}
			for(int i = 1; i < uh - 1; i ++)
			{
				array[(y+i)*cols+x] = color;
				array[(y+i)*cols+x+uw-1] = color;
			}
		}
		else if(rect_width < 0 && rect_height < 0)
		{
			for(int i = 0; i < uw; i ++)
			{
				array[x-i+y*cols] = color;
				array[x-i+(y-uh+1)*cols] = color;
			}
			for(int i = 1; i < uh - 1; i ++)
			{
				array[(y-i)*cols+x] = color;
				array[(y-i)*cols+x-uw+1] = color;
			}
		}
		else if(rect_width > 0 && rect_height < 0)
		{
			for(int i = 0; i < uw; i ++)
			{
				array[x+i+y*cols] = color;
				array[x+i+(y-uh+1)*cols] = color;
			}
			for(int i = 1; i < uh - 1; i ++)
			{
				array[(y-i)*cols+x] = color;
				array[(y-i)*cols+x+uw-1] = color;
			}
		}
		else if(rect_width < 0 && rect_height > 0)
		{
			for(int i = 0; i < uw; i ++)
			{
				array[x-i+y*cols] = color;
				array[x-i+(y+uh-1)*cols] = color;
			}
			for(int i = 1; i < uh - 1; i ++)
			{
				array[(y+i)*cols+x] = color;
				array[(y+i)*cols+x-uw+1] = color;
			}
		}
	}
}