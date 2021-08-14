// Program: EG0610.c
// Description: strcat 

#include <stdio.h>

int stringlength ( char * str )
{
	int count = -1;
	while ( str[++count] );
	return count;
}

char * stringconcatenate ( char * str1, const char * str2)
{
	int len;
	len = stringlength ( str1 );
	
	str1 += len;
	len += stringlength ( str2 );
	
	while ( *str1 = *str2)
		str1++, str2++;
	
	return str1 - len;
}



int main ( void )
{
	char str1[] = "Hello World!";
	char str2[] = "olympic";
	char * str3;
	// CANNOT
	//char * str1 = "Hello World!";
	//char * str2 = "olympic";
	
	
	printf("\n%s\n%s\n", str1, str2);
	
	str3 = stringconcatenate ( str1, str2 );
	
	printf("\n%s\n%s\n%s\n", str1, str2, str3);
	
	return 0;
}
