// Program: EX0414.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int nums[10];
	int i, j;
	int count = 10;
	
	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &nums[i]);
	}
	
	for (i = 0; i < 10 ;i++)
	{
		for ( j = i+1; j < 10; j++)
		{
			if (nums[i] == nums[j])
			{
				count--;
				break;
			}
		}
	}
	
	printf("%d", count);
	
	return 0;
}
