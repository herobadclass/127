#include <stdio.h>

int main(void)
{
	float i = 0;
	float total = 0;
	int count = 0;
	float mean;
	float min = 100000;
	float max = -100000;
	while(scanf("%f", &i) != EOF)
	{
		count = count + 1;
		total = total + i;
		mean = total/count;
		if(i < min)
		{
			min = i;
		}
		if(i > max)
		{
			max = i;
		}
	}
	printf("%.2f %.2f %.2f\n", min, max, mean);
	return 0;
}
		
