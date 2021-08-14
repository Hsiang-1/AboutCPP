// Program: EG0305.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int year;
	scanf("%d", &year);
	
	if( ( (year%100 != 0) && (year%4 != 0)) || ( (year%100 == 0) && (year%400 != 0)) )
		printf("no");
	else
		printf("yes!");
	
	return 0;
}
