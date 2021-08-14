// Program: EG0307.c
// Description: ... 

#include <stdio.h>
#include <math.h>
int main ( void )
{
	float a, b, c;
	float delta, delta2, root1, root2;
	
	scanf("%f,%f,%f", &a,&b,&c);
	
	delta = b * b - 4 * a * c;
	
	if(delta < 0)
	{
		printf("No real root!");
		return 0;
	}
	if(delta == 0)
	{
		printf("2 equivalent root: %f", -b/2/a);
		return 0;
	}
	delta2 = sqrt(delta);
	root1 = (-b+delta2)/2/a;
	root2 = (-b-delta2)/2/a;
	printf("roots: %d, %d", root1, root2);	
	
	return 0;
}
