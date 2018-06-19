#include <stdio.h>

int InRectangle(float pt[2], float rect[4])
{
	int x;
	int y;
	if(rect[0] < rect[2])
	{
		if(pt[0] >= rect[0] && pt[0] <= rect[2])
		{
			x = 1;
		}
		else
		{
			x = 0;
		}
	}
	else
	{
		if(pt[0] <= rect[0] && pt[0] >= rect[2])
		{
			x = 1;
		}
		else
		{
			x = 0;
		}
	}
	if(rect[1] < rect[3])
	{
		if(pt[1] >= rect[1] && pt[1] <= rect[3])
		{
			y = 1;
		}
		else
		{
			y = 0;
		}
	}
	else
	{
		if(pt[1] <= rect[1] && pt[1] >= rect[3])
		{
			y = 1;
		}
		else
		{
			y = 0;
		}
	}
	if(x == 1 && y == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
