// Program: EG0604.c
// Description: swap function 

#include <stdio.h>


void swap ( int *, int *);

int main ( void )
{
	int a = 10;
	int b = 15;
	printf("%5d%5d\n", a, b);
	
	swap( &a, &b);
	printf("%5d%5d\n", a, b);	
	
	return 0;
}

void swap ( int * a, int * b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

