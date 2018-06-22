/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
	for(int y = 0; y < rows; y++)
	{
		for(int x = 0; x < cols; x++)
		{
			set_pixel(array, cols, rows, x, y, 0);
		}
	}
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
	uint8_t* cp = malloc(cols * rows * sizeof(uint8_t));
	if(cp == NULL)
	{
	  return NULL;
	}
	for(int y = 0; y < rows; y++)
	{
		for(int x = 0; x < cols; x++)
		{
			uint8_t color = get_pixel(array, cols, rows, x, y);
			set_pixel(cp, cols, rows, x, y, color);
		}
	}
	return cp;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
	// your code here
	uint8_t minium = array[0];
	for(int i = 1; i < cols * rows; i ++)
	{
		if(array[i] < minium)
		{
			minium = array[i];
		}
	}
	return minium;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
	// your code here
  	uint8_t maximum = array[0];
	for(int i = 1; i < cols * rows; i ++)
	{
		if(array[i] > maximum)
		{
			maximum = array[i];
		}
	}
	return maximum;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
	// your code here
	for(int i = 0; i < cols * rows; i ++)
	{
		if(array[i] == pre_color)
		{
			array[i] = post_color;
		}
	}
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
	// your code here
	uint8_t temp1;
	uint8_t temp2;
	for(int y = 0; y < rows; y ++)
	{
		for(int x = 0; x < cols/2; x ++)
		{
			temp1 = get_pixel(array, cols,rows,x,y);
			temp2 = get_pixel(array,cols,rows,cols-x-1,y);
			set_pixel(array,cols,rows,x,y,temp2);
			set_pixel(array,cols,rows,cols-x-1,y,temp1);
		}
	}	
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
    // your code here
	uint8_t temp;
	for(int x = 0; x < cols; x ++)
	{
		for(int y = 0; y < rows/2; y++)
		{
			temp = array[y*cols+x];
			array[y*cols+x] = array[cols*(rows-1)-cols*y+x];
			array[cols*(rows-1)-cols*y+x] = temp;
		}
	}
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
	for(int i = 0; i < rows; i ++)
	{
		for(int j= 0; j <cols; j ++)
		{
			if(array[i*cols+j] == color)
			{
				*y = i;
				*x = j;
				return 1;
			}
		}
	}
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // your code here
	for(int i = 0; i < rows; i ++)
	{
		for(int j= 0; j <cols; j ++)
		{
			array[i*cols+j] = 255 - array[i*cols+j];
		}
	}
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
	// your code here
	for(int i = 0; i < rows*cols; i ++)
	{
		if(array[i]*scale_factor > 255)
		{
			array[i] = 255;
		}
		else
		{
			array[i] = round(array[i] * scale_factor);
		}
	}
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
	// your code here
	int mi = min(array, cols, rows);
	int ma = max(array, cols, rows);
	for(int i = 0; i < cols*rows; i++)
	{
		array[i] = round((255.0/(ma-mi))*(array[i] - mi));
	}
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
	// your code here
	uint8_t* new_array = malloc(sizeof(uint8_t)*(cols/2)*(rows/2));
	for(int y = 0; y < rows/2; y++)
	{
		for(int x = 0; x < cols/2; x++)
		{
			int temp1 = get_pixel(array, cols,rows,2*x,2*y);
            int temp2 = get_pixel(array, cols,rows,2*x+1,2*y);
            int temp3 = get_pixel(array, cols,rows,2*x,2*y+1);
            int temp4 = get_pixel(array, cols,rows,2*x+1,2*y+1);
			int average = round((temp1+temp2+temp3+temp4)/4.0);
			set_pixel(new_array,cols/2,rows/2,x,y,average);
		}
	}
	return new_array;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
	// your code here
	assert(left<= right);
    assert(top <=bottom);
    assert(top>=0);
    assert(left>=0);
    assert(bottom<=rows);
    assert(right<=cols);
	
	if ((top!=bottom) && (right!= left))
	{
		for (int y = top; y < bottom; y++)
		{
			for (int x = left; x < right; x++)
			{
				set_pixel(array, cols, rows, x, y, color); 
			}
		}
	}
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
    // your code here
	assert(left<= right);
    assert(top <=bottom);
    assert(top>=0);
    assert(left>=0);
    assert(bottom<=rows);
    assert(right<=cols);
	
	long int sum = 0;
	if ((top==bottom) || (right== left))
	{
		return sum;
	}
	else
	{
		for (int y = top; y < bottom; y++)
		{
			for (int x = left; x < right; x++)
			{
				sum = sum + get_pixel(array, cols, rows, x, y);
			}
		}
	}
    return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
    // your code here
	assert(left<= right);
    assert(top <=bottom);
    assert(top>=0);
    assert(left>=0);
    assert(bottom<=rows);
    assert(right<=cols);
	
	if ((top==bottom) || (right== left))
	{
		return NULL;
	}
	else
	{
		int new_cols = right-left;
		int new_rows = bottom - top;
		uint8_t* new_array = malloc(sizeof(uint8_t)*(new_cols)*(new_rows));
		for (int y = top; y < bottom; y++)
		{
			for (int x = left; x < right; x++)
			{
				uint8_t temp = get_pixel(array, cols, rows,x,y);
				set_pixel(new_array,new_cols,new_rows,x-left,y-top,temp);
			}
		}
		return new_array;
	}
    return NULL;
}


