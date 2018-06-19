#include <stdio.h>

int main()
{	
	int k;
	int c = 0;
	int total = 0;
	int max = 0;
	int arr[80] = {-1};
	while(scanf("%d", &k) != -1)
	{
		arr[c] = k;
		c = c + 1;
		total = total + 1;
	}
	
	for(int i = 0; i < total; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	
	for(int i = max; i > 0; i--)
	{
		for(int j = 0; j < total; j++)
		{
			if(arr[j] == i)
			{
				printf("#");
				arr[j] = arr[j] - 1;
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
			
