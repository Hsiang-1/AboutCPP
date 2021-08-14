// Program: EX0514.c
// Description: ... 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
int main ( void )
{
	int *nums;
	int n;
	int i, j, k;
	int count;
	
	scanf("%d", &n);
	count = n;
	
	nums = (int *) malloc ( sizeof(int) * n);
	
	for ( i = 0; i < n; i++)
		scanf("%d", (nums + i));
	
	for ( i = 0; i < count - 1; i++)
		for ( j = i + 1; j < count; j++)
			if ( nums[j] == nums[i])
			{
				for ( k = j; k < count; k++)
					nums[k] = nums[k+1];
				count--;
				j--;
			}
	
	for ( i = 0; i < count; i++)
		printf("%d ", nums[i]);	
	
	//printf("\n%d",count);
	
	return 0;
}
