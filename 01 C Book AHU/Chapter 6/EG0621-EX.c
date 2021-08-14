// Program: EG0621-EX.c
// Description: 

#include <stdio.h>

#define M 5+6
#define N 1+2+3
//#define M (5+6)
//#define N (1+2+3)

#define SUM N+M

#define MAX(x,y) (x>y?x:y)

//the parameter is a string !!! string !!!


int main ( int argc, char * argv[] )
{
	printf("%d\n", M * N * M);
	
	#if 1
		printf("yes");
	#else
		printf("no");
	#endif
	
	return 0;
}




