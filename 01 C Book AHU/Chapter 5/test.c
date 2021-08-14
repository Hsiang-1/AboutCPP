// Program: test.c
// Description: the return value of equal operation
//				the value of the expression

#include <stdio.h>

int main ( void )
{
	int a, b, c;
	int *aa, *bb, *cc;
	
	a = 1;
	b = 1;
	printf("\n%5d%5d\n", a, b);
	
	b = (a++);
	printf("\n%5d%5d\n", a, b);
	
	a = 1;
	b = 1;
	b = (++a);
	printf("\n%5d%5d\n", a, b);
	
	a = 1;
	b = 1;
	b = ( a = 5 );
	printf("\n%5d%5d\n", a, b);
	
	a = 1;
	b = 1;
	b = a = 5;
	printf("\n%5d%5d\n", a, b);
	
	a = 1;
	b = 1;
	b = (a += 7);
	printf("\n%5d%5d\n", a, b);
	
	// attention
	a = 1;
	b = 1;
	b = (a += 2) + (a += 2);
	printf("\n%5d%5d\n", a, b);
	
	a = 1;
	b = 1;
	a += 2;
	a += 2;
	b = a + a;
	printf("\n%5d%5d\n", a, b);
	
	a = 1;
	b = 2;
	c = 3;
	aa = &a;
	bb = &b;
	cc = &c;
	printf("\n%5d%5d%5d\n", *aa, *bb, *cc);
	
	// the same as that attention
	a = 1;
	b = 2;
	c = 3;
	aa = &a;
	bb = &b;
	cc = &c;
	cc = aa = bb;
	printf("\n%5d%5d%5d\n", *aa, *bb, *cc);
	
	a = 1;
	b = 2;
	c = 3;
	aa = &a;
	bb = &b;
	cc = &c;
	cc = ( aa = bb );
	printf("\n%5d%5d%5d\n", *aa, *bb, *cc);

	puts("\n---------------------------------------------------");
	puts("Press any key to continue...");
	getchar();
	return 0;
} 
