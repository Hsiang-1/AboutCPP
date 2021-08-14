// Program: EG0205.c
// Description: ... 

#include <stdio.h>
#include <math.h> 
void main ( void )
{
	float a, b, c;
	float p, s;
	
	scanf("%f,%f,%f",&a,&b,&c);
	p = (a+b+c)/2;
	s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%1.0f", s);
	
}
