#include <stdio.h>
#include "image.hpp"

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

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor )
{
	delete[] pixels; 
 	uint8_t pixels[width*height];
 	if(pixels == NULL)
	{
		return 1;
 	}
 	for(int i=0; i < width*height; i++)
 	{
		pixels[i] = fillcolor;
 	}
 	return 0;
}

int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color )
{
	if(pixels == NULL)
	{
 		return 1;
 	}
 	if(x < cols && y < rows && x >= 0 && y >= 0)
	{
		pixels[y*cols+x] = color;
		return 0;
 	}
 	return 1;
}

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp )
{
	if(pixels == NULL){
 		return 1;
 	}
	if(x < cols && y < rows && x >= 0 && y >= 0)
	{
		*colorp = pixels[y*cols+x];
		return 0;
	}
	return 1;
}