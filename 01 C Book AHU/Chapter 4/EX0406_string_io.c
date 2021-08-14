// Program: EX0406.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	char str1[10], str2[10];
	char c;
	int i;
	
	i = 0;
	while ( '\n' != (c = getchar()) )
	{
		str1[i] = c;
		i++;
	}
	
	i = 0;
	while ( '\n' != (c = getchar()) )
	{
		str2[i] = c;
		i++;
	}
	
	
	//puts("please input str1: ");
	//gets(str1);
	
	
	
	for( i = 0; i < 10; i++)
	{
		if( str1[i] != str2[i])
		{
			printf("%d", str1[i] - str2[i]);
			break;
		}
	}
	
	
	return 0;
}
