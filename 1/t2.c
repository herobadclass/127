#include <stdio.h>
#include <limits.h>

int main( void )
{
	int char_size = sizeof(char)*CHAR_BIT;
	int unsigned_char_size = sizeof(unsigned char)*CHAR_BIT;
	int int_size = sizeof(int)*CHAR_BIT;
	int unsigned_int_size = sizeof(unsigned int)*CHAR_BIT;
	int long_size = sizeof(long)*CHAR_BIT;
	int unsigned_long_size = sizeof(unsigned long)*CHAR_BIT;
	int float_size = sizeof(float)*CHAR_BIT;
	int double_size = sizeof(double)*CHAR_BIT;
	int long_double_size = sizeof(long double)*CHAR_BIT;
	printf( "%d ", char_size );
	printf( "%d ", unsigned_char_size );
	printf( "%d ", int_size );
	printf( "%d ", unsigned_int_size );
	printf( "%d ", long_size );
	printf( "%d ", unsigned_long_size );
	printf( "%d ", float_size );
	printf( "%d ", double_size );
	printf( "%d\n", long_double_size );
}
