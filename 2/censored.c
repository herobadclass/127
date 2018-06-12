#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int c;
	char word[128];
	int i = 0;
	while((c=getchar()) != EOF)
	{
		if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '\'')
		{
			word[i] = c;
			i = i + 1;
		}
		else
		{
			for(int j = 1; j < argc; j++)
			{
				char* result = strstr(word, argv[j]);
				if(result != NULL)
				{
					memset(&word[0], 0, sizeof(word));
					strcpy(word, "CENCORED");
				}
			}
			printf("%s%c",word,c);
			i = 0;
			memset(&word[0], 0, sizeof(word));
		}
	}
	return 0;
}
