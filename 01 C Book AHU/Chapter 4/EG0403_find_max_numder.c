// Program: EG0403.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int nums[10];
	int i;
	int maxnum, location;
	
	location = 0;
	
	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &nums[i]);
		if (i==0)
			maxnum = nums[0];
		
		if(nums[i] > maxnum)
		{
			location = i;
			maxnum = nums[i];
		}
	}
	
	printf(" the %d place,  %d", location+1 , maxnum);
	
	return 0;
}
