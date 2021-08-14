// Program: EG0620.c
// Description: static variable to achieve factorial table

#include <stdio.h>

int factorial( int n)
{
	static int f = 1;
	return f *= n;
}

int main ( int argc , char * argv[] )
{
	int i;
	for (i = 1; i <= 10; i ++ )
		printf(" %2d! = %d\n", i, factorial(i));
	
	return 0;
}





