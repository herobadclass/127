#include <stdio.h>

int main()
{
	int c;
	double count[26] = {0};
	double total = 0;
	int letter;
	double freq;
	while((c = getchar()) != EOF)
	{
		if(c >= 'a' && c <= 'z')
		{
			count[c - 97] = count[c - 97] + 1;
			total = total + 1;
		}
		else if(c >= 'A' && c <= 'Z')
		{
			count[c - 65] = count[c - 65] + 1;
			total = total + 1;
		}
	}
	for(int i = 0; i < 26; i++)
	{
		if(count[i] > 0)
		{
			letter = i + 97;
			freq = count[i]/total;
			printf( "%c %.4f\n", letter, freq);
		}
	}
	return 0;
}
