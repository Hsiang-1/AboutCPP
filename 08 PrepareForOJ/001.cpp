#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;


int reverse (int x){
	int revx = 0;
	while(x!=0){
		revx *= 10;
		revx += x % 10;
		x /= 10;
	}
	return revx;
}


int main (void)
{
	
	int num;
	for( num=0; num < 256; num++)
		if( num*num == reverse(num * num))
			printf("%d\n", num);
	
	
	return 0;
}
