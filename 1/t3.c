#include <stdio.h>
#include <math.h>
 
int main(void)
{
	float i = 0;
	scanf("%f", &i );
	printf("%d %d %d\n", (int)floor(i), (int)round(i), (int)ceil(i));
	return 0;
}
