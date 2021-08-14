// Program: EG0505.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int nums[5];
	int *ptr = nums;
	int i;
	
	for ( i = 0; i < 5; i++, ptr++)
		scanf("%d", ptr);
	
	ptr--;
	
	for ( i = 0; i < 5; i++, ptr--)
		printf("%5d", *ptr);
	
	
	return 0;
}
