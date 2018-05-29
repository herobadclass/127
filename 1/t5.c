#include <stdio.h>
#include <math.h>
 
int main(void)
{
	float i = 0;
	while(scanf("%f", &i ) != EOF)
	{
		printf("%d %d %d\n", (int)floor(i), (int)round(i), (int)ceil(i));
	}
	if(scanf("%f", &i ) == EOF)
	{
		printf("Done.\n");
	}
	return 0;
}
