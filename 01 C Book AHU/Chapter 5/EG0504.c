// Program: EG0504.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int nums[5] = { 5, 4, 3, 2, 1};
	//int * ptr = nums;
	int *ptr = &nums[0];
	int i;
	
	printf("%5d\n", *ptr);
	
	printf("%5d\n",    ptr[3]    );
	printf("%5d\n",   *(ptr+3)   );
	printf("%5d\n",  *(nums+3)   );
	
	return 0;
}
