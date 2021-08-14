// Program: EG0302.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int number;
	int times = 100000;
	scanf("%d", &number);
	
	while(1 != times)
	{
		times = times / 10;
		printf("%d\n", number/times);
		number = number%times;
	}
	
	return 0;
}
