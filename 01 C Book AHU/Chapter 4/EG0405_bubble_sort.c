// Program: EG0405.c
// Description: bubble sort

#include <stdio.h>
int main ( void )
{
	int nums[10] = { 23,54,66,43,78,11,67,9,69,99};
	int i, j;
	
	for ( i = 0; i < 10; i++)
	{
		for ( j = 0; j < 10 - i - 1; j++)
		{
			if( nums[j] < nums [j+1])
			{
				nums[j] = nums[j] + nums[j+1];
				nums[j+1] = nums[j] - nums[j+1];
				nums[j] = nums [j] - nums[j+1];
			}
		}
	}
	
	for ( i = 0; i < 10; i++)
		printf("%3d", nums[i]);
	
	return 0;
}
