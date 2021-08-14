// Program: EG0616.c
// Description: qsort function call 

#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int comp ( void *p, void *q)
{
	return ( * (int *)p - * (int *) q);
	// return  - ( * (int *)p - * (int *) q);
}

int main ( void )
{
	int i;
	int num[SIZE] = {5,6,8,2,9,1,3,0};
	
	
	// stdlib.h
	// void qsort (void *base, size_t nmem, size_t size, int (*comp)(const void*, const void*));
	qsort( num, SIZE, sizeof(int), comp);
	
	
	for ( i = 0; i < SIZE; i++)
		printf("%3d", num[i]);
	
	return 0;
}
