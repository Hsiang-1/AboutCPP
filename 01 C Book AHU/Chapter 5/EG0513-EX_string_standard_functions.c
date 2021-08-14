// Program: EX0513-EX.c
// Description: string standard functions

#include <stdio.h>
#include <string.h>


int main ( void )
{
	char str1[100], str2[100];
	
	gets( str1 );
	puts( str1 );
	
	// str1 = "hello world";		// wrong
	
	printf("\n%d\n", strlen(str1));
	
	strcpy(str2, str1);
	puts(str2);
	
	strcat(str2, "Hello World!");
	puts(str2);	
	
	return 0;
}
