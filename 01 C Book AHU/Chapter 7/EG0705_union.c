// Program: EG0705.c
// Description: ... 

#include <stdio.h>

int main ( int argc , char * argv[] )
{
	struct
	{
		char name[10];
		int age;
		char job;
		union
		{
			int classa;
			char office[10];
		} department;
	} employ[3];
	
	int i;
	for ( i = 0; i < 3; i ++ )
	{
		printf("Input name, age, job and department\n");
		scanf("%s %d %c", employ[i].name, &employ[i].age, &employ[i].job);
		if ( employ[i].job == 's' )
			scanf(" %d", &employ[i].department.classa);
		else
			scanf(" %s", employ[i].department.office);
	}
	printf("\n\n-------------------------------------------\n");
	printf("name\tage job class/office\n");
	for ( i = 0; i < 3; i ++)
	{
		if ( employ[i].job == 's' )
			printf("%s\t%3d%3c%12d\n", employ[i].name, employ[i].age,
					employ[i].job, employ[i].department.classa);
		else
			printf("%s\t%3d%3c%12s\n", employ[i].name, employ[i].age,
					employ[i].job, employ[i].department.office);
	}
	
	return 0;
}





