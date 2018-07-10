#include <stdio.h>
#include "point_array.h"

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
	pa->len = 0;
	pa->reserved = 0;
	pa->points = NULL;
}

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
	pa->len = 0;
	pa->reserved = 0;
	free(pa->points);
}

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
	if(p == NULL){
		return 0;
	}

	pa->len = pa->len + 1;
	pa->points = realloc(pa->points, pa->len*sizeof(point_t));
	if(pa == NULL){
		return 1;
	}

	pa->points[pa->len-1].x = p->x;
	pa->points[pa->len-1].y = p->y;
	pa->points[pa->len-1].z = p->z;
	return 0;
}

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
// Return 0 on success and 1 on failure.
int point_array_remove( point_array_t* pa, unsigned int i ){
	if(i >= pa->len){
		return 1;
	}

	pa->points[i].x = pa->points[pa->len-1].x;
	pa->points[i].y = pa->points[pa->len-1].y;
	pa->points[i].z = pa->points[pa->len-1].z;

	pa->len = pa->len - 1;
	pa->points = realloc(pa->points, pa->len*sizeof(point_t));
	return 0;
}
