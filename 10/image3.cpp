#include "image3.hpp"
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
Image::Image()
{
	cols = 0;
	rows = 0;
	pixels = NULL;
}

Image::~Image()
{
 	if(pixels != NULL)
	{
 		for(int i = 0; i < rows; i++)
		{
		    delete[] pixels[i];
		}
		delete [] pixels;
 	}
}

int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor )
{
 	if(pixels != NULL)
	{
 		for (int i = 0; i < rows; i++)
		{
 		    delete[] pixels[i];
		}
		delete [] pixels;
 	}
 	pixels = new uint8_t*[height];
	for(int i = 0; i < height; i++)
	{
	    pixels[i] = new uint8_t[width];
	} 	
 	if(pixels == NULL)
	{
 		return 1;
 	}
 	cols = width ;
 	rows = height ;
 	
 	for(int i = 0 ; i < rows ; i++)
	{
 		for(int j = 0 ; j < cols ; j++)
		{
 			pixels[i][j] = fillcolor;
 		}
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
		pixels[y][x] = color;
		return 0;
	}
	return 1;
}
  

int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp )
{
 	if (colorp == NULL || pixels == NULL)
 	{
 		return 1;
 	}
 	if(x < cols && y < rows && x >= 0 && y >= 0)
	{
		*colorp = pixels[y][x];
		return 0;
	}
	return 1;
}

int Image::save( const char* filename )
{
 	if(filename == NULL)
	{
 		return 1;
 	}
 	fstream f;
	f.open(filename, fstream::out);
 	if (!f.is_open())
	{
 		return 1;
 	}
 	if((rows == 0 && cols > 0) || (rows > 0 && cols == 0))
	{
		return 1;
	}
 	if(cols == 0 && rows == 0)
	{		
 		f.close();
 		return 0;
 	}
 	for(int i=0; i < rows; i++)
	{
 		for(int j=0; j < cols; j++)
		{
 			f<<(int)pixels[i][j]<<" ";
 		}
 		f<<endl;
 	}
    f.close();
 	return 0; 	 	
}
int Image::load( const char* filename )
{
 	if(filename == NULL)
	{
		return 1;
	}
	fstream f;
	f.open(filename,ios::in);
	if(!f.is_open())
	{
		return 1;
	}
	f.seekg (0, f.end);
    int length = f.tellg();
    f.seekg (0, f.beg);

    if (length == 0)
	{
 		cols = 0;
 		rows = 0;
 		pixels = NULL;
 		f.close();
    	return 0;
 	}
	int pxl;
	int total = 0;
	int lines = 0;
	char line[1500];
	while(!f.eof())
	{
		f >> pxl;
		total++;
	}
	total = total -1;	
	f.clear();
	f.seekg (0, f.beg);
	
	while(!f.eof())
	{
		f.getline(line,1500,'\n');
		lines ++;
	}
	lines = lines - 1;	
	f.clear();
	f.seekg (0, f.beg);
	if(lines == 0)
	{
		cols = 0;
		rows = 0;
		if(pixels != NULL)
		{
 			for(int i = 0; i < rows; i++)
			{
		  	  delete[] pixels[i];
			}
			delete [] pixels;
			pixels = NULL;	
 		}
		f.close();
		return 0;
	}
	else
	{
		cols = total/lines;
		rows = lines;	
	}
	if(pixels != NULL)
	{
 			for(int i = 0; i < rows; i++)
			{
		  	  delete[] pixels[i];
			}
			delete [] pixels;
 	}		

	pixels = new uint8_t*[rows];
	for(int i = 0; i < rows; ++i)
	{
	    pixels[i] = new uint8_t[cols];
	} 		
	for(int i = 0; i < rows; i++)
	{
 		for(int j = 0; j < cols; j++)
		{
 			f >> pxl;
 			pixels[i][j] = pxl;
 		}
 	}
	f.close();
	return 0;
 }