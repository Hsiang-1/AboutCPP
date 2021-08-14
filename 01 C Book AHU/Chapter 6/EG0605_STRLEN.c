// Program: EG0605.c
// Description: strlen 

#include <stdio.h>

int stringlength ( char *a )
{
	int count = 0;
	while( a[count] != '\0')
	{
		count++;
	}
	return count;
}

// need to remember this
int strlen ( char a[] )
{
	int count = -1 ;
	while ( a[count++] ) ;
	return count;
}


int main ( void )
{
	char a[] = "Hello World!";
	
	printf( "%d", stringlength(a) );
	
	return 0;
}
