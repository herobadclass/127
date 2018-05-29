#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = 0;
	while(scanf("%d", &i) != EOF)
	{
		for(int c = 0; c < i; c++)
		{
			printf("#");
		}
		printf("\n");
	}
	return 0;
}
