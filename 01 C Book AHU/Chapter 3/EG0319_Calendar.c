// Program: EG0319.c
// Description: ... 

#include <stdio.h>
int main ( void )
{
	int month, firstday, maxday, daynum;
	printf("Input the month, firstday, maxday:");
	scanf("%d,%d,%d", &month, &firstday, &maxday);
	
	printf("\n------------------  %2d 月  ------------------\n", month);
	printf("\n    日    一    二    三    四    五    六\n\n");
	
	daynum = 1;
	if(firstday != 7)
		daynum -= firstday;
	
	while(daynum <= maxday)
	{
		if(daynum <= 0)
		{
			printf("      ");
		}
		else
		{
			printf("%6d", daynum);
		}
		if( (daynum+firstday)%7 == 0)
			printf("\n\n");
		
		daynum++;
	}
	
	printf("---------------------------------------------\n", month);
	
	return 0;
}
