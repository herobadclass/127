#include <stdio.h>

typedef struct{
	double x;
	double y;
	double z;
}data;

int get_data(data* data_array, unsigned int len, unsigned int index, data* d){
	if(data_array != NULL && d != NULL && index < len && index >= 0){
		d->x = data_array[index*len];
		d->y = data_array[index*len + 1];
		d->z = data_array[index*len + 2];
		return 1;
	}
	return 0;
}
