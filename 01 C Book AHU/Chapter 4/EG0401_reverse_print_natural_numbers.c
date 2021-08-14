// Program: EG0401.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int nums[5];
	int i;			//index
	
	for (i=0; i < 5; i++)
		scanf("%d", &nums[i]);
	
	for ( i = 4; i >= 0 ; i--)
	{
		if(nums[i] >= 0)
			printf("%d", nums[i]);
	}
	
	
	
	return 0;
}
