// Program: EG0312.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int number;
	float ans, err;
	
	scanf("%d", &number);
	
	err = 1;
	ans = number/2;
	while(err > 1e-6)
	{
		err = (ans + number/ans)/2;
		ans = (ans>err ? ans-err : err-ans);
		err = err + ans;
		ans = err - ans;
		err = err - ans;
	}	
	printf("%f", ans);
	
	return 0;
}
