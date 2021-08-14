// Program: EG0311.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	float pi = 0;
	int i = 1;
	float t = 1;
	
	while ( t > 1e-6)
	{
		if( 1 == i%2 )
			pi = pi + t;
		else
			pi += - t;
		i++;
		t = 1.0/(2*i-1);
	}
	printf("pi = %f\n", pi * 4);	
	
	return 0;
}
