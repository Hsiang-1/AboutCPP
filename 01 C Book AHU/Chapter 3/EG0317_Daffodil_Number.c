// Program: EG0317.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int a, b, c, num;
	
	for( num = 100; num < 1000; num++)
	{
		a = num/100;
		b = (num/10)%10;
		c = num%10;
		if ( num == (a*a*a+b*b*b+c*c*c))
			printf("%5d", num);
	}
	
	printf("\n-----------------\n");
	
	for( a=1; a<10; a++)
		for( b=0; b<10; b++)
			for( c=0; c<10; c++)
				if( (100*a+10*b+c) == (a*a*a+b*b*b+c*c*c))
					printf("%5d", (100*a+10*b+c) );

	
	
	return 0;
}
