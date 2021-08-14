// Program: EG0511.c
// Description: reverse string 

#include <stdio.h>
int main ( void )
{	
	// the return value of equals operation
	/*
	int a = 1, b = 1;
	
	printf("\n%5d,%5d\n", a, b);
	
	b = (a = 2);
	printf("\n%5d,%5d\n", a, b);
	
	a = 1;
	b = 1;
	b = (a += 2);
	printf("\n%5d,%5d\n", a, b);
	
	a = 1;
	b = 1;
	b = (a = 2) + (a = 5);
	printf("\n%5d,%5d\n", a, b);
	
	a = 1;
	b = 1;
	b = (a += 2) + (a += 2);
	printf("\n%5d,%5d\n", a, b);
	*/
	
	char str[] = "testSrting";
	char *begin, *end;
	char tmp;
	// CANNOT define *tmp !!!
	
	
	printf("%s\n\n", str);
	
	begin = str;
	end = str;
	// begin = end = str;
	// begin = ( end = str) ;
	
	while ( *end != '\0')
		end++;
	end--;
	
	while ( begin < end)
	{
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
	
	printf("%s", str);
	
	return 0;
}
