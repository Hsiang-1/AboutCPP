// Program: EG0406.c
// Description: Binsreach 

#include <stdio.h>
#define MAXSIZE 10

int main ( void )
{
	
	int nums[MAXSIZE] = {0,1,2,3,4,5,6,7,8,9};
	int begin=0, end=MAXSIZE-1, mid, x;
	
	scanf("%d", &x);

	while (begin < end)
	{
		mid = (begin + end ) / 2;
		
		if(nums[mid] == x)
		{
			printf("\n\n%d\n", mid);
			return 0;
		}
		
		if (nums[mid] > x)
		{
			end = mid-1;				//attention
		}
		else
		{
			begin = mid+1;				//attention
		}
	}
	
	printf("no number!");
	
	return 0;
}
