#include <stdio.h>
#include <stdint.h>
#include <fstream>
#include <image2.hpp>
using namespace std;
Image::Image()
{
	cols = 0;
	rows = 0;
	pixels = NULL;
}

Image::~Image()
{
	if( pixels != NULL ) 
	{
		delete[] pixels; 
    }
}
/* Changes the size of an image, allocating memory as necessary, and
setting all pixels to fillcolor. Returns 0 on success, or a
non-zero error code.*/ 
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor )
{
	if (pixels != NULL)
	{
 		delete[] pixels;
 	}
 	pixels = new uint8_t[width][height];
 	if (pixels == NULL)
	{
 		return 1;
 	}
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			pixels[i][j] = fillcolor;
		}
	}
	cols = width;
 	rows = height;
 	return 0;
}
/* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color )
{
	if(x > cols || y > rows)
	{
		return 1;
	}
	pixels[y][x] = color;
	return 0;
}
/* Gets the color of the pixel at (x,y) and stores at the address pointed to 
by colorp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp )
{
	if(x > cols || y > rows)
	{
		return 1;
	}
	*colorp = pixels[y][x];
	return 0;
}
/* Saves the image in the file filename. In a format that can be
loaded by load().  Returns 0 on success, else a non-zero error
code. */
int Image::save( const char* filename )
{
	if(filename == NULL)
	{
		return 1;
	}
	fstream f;
	f.open(filename);
	if(cols == 0 && rows == 0)
	{
		f.close();
		return 0;
	}
	else if(cols == 0 || rows == 0);
	{
		f.close;
		return 1;
	}
	else
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				f << (int)pixels[i][j] <<" ";
			}
			f << endl;
		}
	}
	f.close;
	return 0;
}
/* Load an image from the file filename, replacing the current
image size and data. The file is in a format that was saved by
save().  Returns 0 success, else a non-zero error code . */
int Image::load( const char* filename )
{
	if(filename == NULL)
	{
		return 1;
	}
	fstream f;
	f.open(filename);
	
	delete[] pixels;
	pixels = new uint8_t[cols*rows];
	
	int pxl
	for(int i = 0, i < rows; i ++)
	{
		for(int j = 0; j < cols; j++)
		{
			fp >> pxl;
			pixels[i][j] = pix;
		}
	}
	fp.close();
}