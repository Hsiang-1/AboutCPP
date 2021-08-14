// Program:EG0104.c
// Description: ... 

#include <stdio.h>
void main ( void )
{
	float a,b,c,d,min;
	
	printf("please input 4 float nums:");
	scanf("%f,%f,%f,%f", &a, &b, &c, &d);
	
	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	if (min > d)
		min = d;
	
	printf("the min one is: %f \n", min);
}
