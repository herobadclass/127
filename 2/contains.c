#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char* arr1 = argv[1];
	char* arr2 = argv[2];
	char* result = strstr(arr1, arr2);
	if(result != NULL)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}
