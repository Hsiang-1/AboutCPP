// Program: EG0404.c
// Description: selection sort 

#include <stdio.h>
int main ( void )
{
	int nums[10] = { 23,54,66,43,78,11,67,9,69,99};
	int i, j;
	int maxnum, location;
	
	// from big to small
	for ( i = 0; i < 10; i++)
	{
		maxnum = nums[i];
		location = i;
		for ( j = i; j < 10; j++)
		{
			if ( nums[j] > maxnum)		// this > decided the sequence
			{
				maxnum = nums[j];
				location = j;
			}
		}
		nums[location] = nums[i];
		nums[i] = maxnum;
	}
	
	for ( i = 0; i < 10; i++)
		printf("%3d", nums[i]); 
	
	
	
	return 0;
}
