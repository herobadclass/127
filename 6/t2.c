#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename )
{
	if(ia == NULL)
	{
		return 1;
	}

	FILE* f = fopen(filename, "w");
	if(f == NULL)
	{
		return 1;
	}

	fprintf(f,"[");
	for(int i = 0; i < ia->len; i ++)
	{
		fprintf(f," %d",ia->data[i]);
		if(i != ia->len-1)
		{
			fprintf(f, ",");
		}
	}
	fprintf(f, " ]");
	fclose(f);
	return 0;
}
	


/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename )
{
	FILE* f = fopen(filename, "r");
	if(f == NULL)
	{
		return NULL;
	}

	int len = 0;
	while(!feof(f))
	{
		char c = getc(f);
		if(c == ',')
		{
			len = len + 1;
		}
	}
	fseek(f, 0, SEEK_SET);
	intarr_t* arr = malloc(sizeof(intarr_t));
	if (arr == NULL)
    	{
	        return NULL;
	}
	if(len == 0)
	{
		arr->len = 0;
		arr->data = NULL;
		return arr;
	}
	
	arr->data = malloc(sizeof(int)*len);
	arr->len = len + 1;
	
	int j;
	for(int i = 0; i < arr->len; i ++)
	{
		while(fscanf(f, "%d", &j) != 1)
		{
			fseek(f, 1, SEEK_CUR);
		}
		arr->data[i] = j;
	}
	fseek(f, 0, SEEK_SET);
	fclose(f);
	return arr;
}
