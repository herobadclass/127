#include <stdio.h>
#include <math.h>

int main(void)
{
	int i = 0;
	scanf("%d", &i);
	int x = i;
	scanf("%d", &i);
	int y = i;
  scanf("%d", &i);
  int z = i;

  int z1 = 0;
  int z2 = z;
  int x1 = 0;
  int x2 = x/2;
	int dx = x2 - x1;
  int dz = z2 - z1;

  for(int j = z2-1; j >= z1; j--) 
  {
    int left = x1 + dx * (j - z1) / dz;
    int right = ceil( (x-1) + -j * (x/(2.0*z)) );  
    if(left > 0)
    {
      for(int i = 0; i < left; i++)
      {
        printf(" ");
      }
    }
    if(j == z1 || j == (z2-1))
    {
      for(int i = left; i < (right+1); i++)
      {
        printf("#");
      }
      printf("\n");
    }
    else
    {
      printf("#");
      for(int i = left; i < (right-1); i ++)
      {
       printf(".");
      }
      printf("#\n");
    }
  }
}

