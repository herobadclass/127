#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
	char hold[1];
	int len = strlen(s) - 1;
	for(int i = 0; i < (len/2); i++)
	{
		hold[0] = s[i];
		s[i] = s[len-i];
		s[len-i] = hold[0];
	}
}
