// Program: EG0510.c
// Description: copy string by pointer

#include <stdio.h>
int main ( void )
{
	char str1[] = "I am a teacher.", *from = str1;
	char str2[] = "You are a student.", *to = str2;
	
	printf("%s \n", str1);
	printf("%s \n", to);
	// %s need a pointer point to a char array!
	
	
	// the end of the string has a '\0'
	for ( ; *from != '\0' ; from++, to++)
		*to = *from;
	
	printf("\n%s", str2);

	return 0;
}
