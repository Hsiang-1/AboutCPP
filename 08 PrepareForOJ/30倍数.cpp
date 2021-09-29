#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int main (void)
{
	int num;
	int sum = 0;
	int wei[10] = {0};
	int i;
	int out;
	
	scanf("%d", &num);
	
	while(num != 0)
	{
		i = num % 10;
		wei[i] += 1;
		num = num / 10;
	}
	
	for(i=0;i<10;i++)
		sum += (wei[i] * i);
	
	if(wei[0]==0 || (sum%3 != 0))
	{
		printf("-1");
		return 0;
	}
	
	sum = 0;
	for(i=1;i<10;i++)
	{
		while(wei[i] != 0)
		{
			out += (i * pow(10, sum));
			sum += 1;
			wei[i] -= 1;
		}
	}
	
	out *= pow(10, wei[0]);
	
	printf("%d",out);
	
	return 0;
} 
