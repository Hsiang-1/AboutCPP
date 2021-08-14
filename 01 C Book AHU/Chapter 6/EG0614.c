// Program: EG0614.c
// Description: ... 

#include <stdio.h>

char *weekname ( int week )
{
	// equals to  ( * ( name[] ) ) , the priority
	char * name[] = { "Sunday", "Monday", "Tuesday",
						"Wednesday", "Thursday", "Friday", "Saturday", "Illegal day"};
	return ( (week>0 && week<6) ? name[week] : name[7]);
}

int main ( void )
{
	
	printf("\n%s\n", weekname( 5 ));
	printf("\n%s\n", weekname( 9 ));
	
	return 0;
}
