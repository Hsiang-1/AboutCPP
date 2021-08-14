// Program:EG0103.c
// Description: ... 

#include <stdio.h>
void main ( void )
{
	int first, second, max;
	
	printf("please input 2 integer:");
	scanf("%d,%d", &first, &second);
	
	max = first;
	if (max < second)
		max = second;
	
	printf("the max one is: %d \n", max);
	getchar();
}
