#include <stdio.h>

int main(void)
{
	int i = 0;
	scanf("%d", &i);
	int w = i;
	scanf("%d", &i);
	int b = i;

	for(int x = 0; x < w; x++)
	{
		printf("#");
	}
	printf("\n");
	
	for(int y = 0; y < (b-2); y++)
	{
		printf("#");
		for(int d = 0; d < (b-2); d++)
		{
			printf(".");
		}
		printf("#\n");
	}

	if(b>1)
	{
		for(int x = 0; x < w; x++)
		{
			printf("#");
		}
		printf("\n");
	}
}
