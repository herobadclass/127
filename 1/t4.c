#include <stdio.h>
#include <math.h>
 
int main(void)
{
	float i = 0;
	scanf("%f", &i );
	if(i == 0)
	{
		printf("scanf error: (%d)\n", (int)i);
	}
	else
	{
		printf("%d %d %d\n", (int)floor(i), (int)round(i), (int)ceil(i));
	}
	return 0;
}
