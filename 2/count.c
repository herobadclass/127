#include <stdio.h>

int main()
{
	long int charcount = 0;
	long int wordcount = 0;
	long int linecount = 0;
	int c;
	int word;
	while((c = getchar()) != EOF)
	{
		charcount = charcount + 1;
		if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '\'')
		{
			word = 1;
		}
		else
		{
			if(word == 1)
			{
				wordcount = wordcount + 1;
			}
			if(c == '\n')
			{
				linecount = linecount + 1;
			}
			word = 0;
		}
	}
	printf("%lu %lu %lu\n", charcount, wordcount, linecount);
	return 0;
}
