// Program: EG0619.c
// Description: static variable 

#include <stdio.h>

int fun( int a )
{
	auto int b = 0;
	static int c = 3;
	b = b + 1;
	c = c + 1;
	return (a + b + c);
}

int main ( int argc , char * argv[] )
{
	int a = 2;
	int i;
	
	for ( i = 0; i < 3; i ++)
		printf("%5d", fun(a));
	
	return 0;
}
