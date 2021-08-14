// Program: EG0607.c
// Description: string compare

#include <stdio.h>


int stringcompare ( char * str1, char * str2)
{
	while ( *str1 && *str2 && *str1 == *str2)
		str1++, str2++;
	return *str1 - *str2;
}


int main ( void )
{
	char *str1 = "Hello World!";
	char str2[] = "Hello String!";

	printf("\n%s\n%s\n", str1, str2);
	
	printf("%d\n", stringcompare( str1, str2));
	
	// the pointer is invariable !! 
	// the value which is the pointer pointed is variable.
	// the formal parameter is invariable, whether pointer or not pointer
	printf("\n%s\n%s\n", str1, str2);
	
	return 0;
}
