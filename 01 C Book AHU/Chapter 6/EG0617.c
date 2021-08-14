// Program: EG0617.c
// Description: ... 

#include <stdio.h>




int main ( int argc , char * argv[] )
{
	int i = -1;
	printf("%d\n\n", argc);
	while( argv[++i] )
	{
		printf("%s\n", argv[i]);
	}
	
	return 0;
}
