#include <stdio.h>
#include "t2.c"

int main()
{
	char s[] = {'a','b','c','d','e'};
	printf("%s\n",s);
	reverse(s);
	printf("%s\n",s);
	return 0;
}
