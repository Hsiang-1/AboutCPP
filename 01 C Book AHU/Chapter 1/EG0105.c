// Program: EG0105.c
// Description: ... 

#include <stdio.h>

int bigger(int a, int b)
{
	if(a<b)
		return b;
	else
		return a;
}

void main ( void )
{
	int first, second, third, max;
	
	printf("please input 3 integer:");
	scanf("%d,%d,%d", &first, &second, &third);
	max = bigger(first,second);
	max = bigger(second,third);
	
	printf("the max one is: %d\n", max); 
}
