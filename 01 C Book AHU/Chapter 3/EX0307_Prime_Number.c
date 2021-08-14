// Program: EX0307.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int number = 2;
	int test = 2;
	int count = 0;
	
	float a,b,c,d;
	
	
	for( test = 2, number = 2; test < number ; test++)
	{
		printf("yes");
	}
	
	
	for ( number = 2; number < 100; number++)
	{
		for ( test = 2; test <= number ; test++)
		{
			if (number == test)
			{
				printf("%3d", number);
				count++;
				if(count%5 == 0)
					printf("\n");
			}
			
			if ( (number % test) == 0)
				break;
		}
	}
	
	printf("\ncount:%3d\n", count);

	return 0;
}
