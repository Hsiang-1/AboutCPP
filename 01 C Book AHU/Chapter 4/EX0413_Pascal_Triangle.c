// Program: EX0413.c
// Description: Pascal's Triangle 

#include <stdio.h>
int main ( void )
{
	/*
	int nums[10][10];
	int i, j;
	
	for ( i = 0; i < 10 ; i++)
	{
		for ( j = 0; j < 10; j++)
		{
			if( i == 0)
				nums[i][j] = 1;
			else
				nums[i][j] = 0;
		}
	}
	*/
	
	int nums[10][10] = {0};
	int i, j;
	
	i = 0;
	for ( j = 0; j < 10; j++)
		nums[i][j] = 1;
	
	
	for ( i = 1; i < 10 ; i++)
	{
		for ( j = 1; j < 10; j++)
		{
			nums[i][j] = nums[i-1][j-1] + nums[i][j-1];
		}
	}
	
	for ( j = 0; j < 10 ; j++)
	{
		for ( i = 0; i < 9-j; i++)
		{
			printf("  ");
		}
		for ( i = 0; i < 10; i++)
		{
			if ( nums[i][j] != 0)
				printf("%5d", nums[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
