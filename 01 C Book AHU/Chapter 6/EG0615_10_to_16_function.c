// Program: EG0615.c
// Description: 10 to 16 

#include <stdio.h>

void reverser ( char * begin, char * end )
{
	char tmp;
	if ( begin < end)
	{
		tmp = * begin;
		* begin = * end;
		* end = tmp;
		reverser( ++begin, --end);
	}
}

void reverse( char *str)
{
	int len = -1 ;
	while ( str[ ++len ]);
	return reverser( str, str+len-1 );	
}

char * itoh ( unsigned int num)
{
	int hex, i = 0;
	static char hexnum[10];
	do
	{
		hex = num%16;
		hexnum[i++] = (hex<=9) ? hex+'0' : hex - 10 + 'A';
	}while ( num /= 16 );
	reverse (hexnum);
	return hexnum;
}

int main ( void )
{
	int num = 1999;
	printf("Hex(%d) = %s\n", num, itoh(num));
	return 0;
}
