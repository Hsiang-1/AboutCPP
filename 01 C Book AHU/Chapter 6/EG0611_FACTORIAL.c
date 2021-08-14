// Program: EG0611.c
// Description: factorial 

#include <stdio.h>

int factorial ( int i )
{
	if ( i == 1 || i == 0)
		return 1;
	else
		return i * factorial( i - 1 );
}


int main ( void )
{
	
	printf("%d", factorial(10) );
	
	return 0;
}
