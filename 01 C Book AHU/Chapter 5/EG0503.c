// Program: EG0503.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int a, b, c;
	int *aa, *bb, *cc;
	int *tmp;
	
	scanf("%d,%d,%d", &a, &b, &c);
	
	printf("\n\n%5d%5d%5d\n\n", a, b, c);
	
	aa = &a;
	bb = &b;
	cc = &c;
	
	// int *cc = &c;
	
	if (*aa < *bb)
		tmp = aa, aa = bb, bb = tmp;
	if (*aa < *cc)
		tmp = aa, aa = cc, cc = tmp;
	if (*bb < *cc)
		tmp = bb, cc = bb, cc = tmp;
		
	printf("%5d%5d%5d", *aa, *bb, *cc);
	
	
	
	
	return 0;
}
