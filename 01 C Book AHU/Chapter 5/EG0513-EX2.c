// Program: EG0513-EX2.c
// Description: ... 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAXLENGTH 30


int main ( void )
{
	char tmp[MAXLENGTH], **words;
	int n;
	int i, j, k;
	
	printf("Please input the quantity of the word:");
	scanf("%d", &n);
	
	// mallocate the words
	if ( (words = (char **) malloc ( sizeof(char * ) * n) ) == NULL)
	{
		printf("Memory allocation failed!");
		return 1;
	}
	
	for ( i = 0; i < n; i++)
	{
		printf("Please input %d word: ", i+1);
		scanf("%s", tmp);
		// gets(tmp);			// wrong
		
		if ( ( words[i] = ( char * ) malloc ( sizeof(char) * (strlen(tmp) + 1) ) ) == NULL )
		{
			printf("Memory allocation failed!");
			return 1;
		}
		
		strcpy( words[i], tmp);
		
	}
	
	// selection sort
	
	for ( i = 0; i < n - 1; i++)
	{
		k = i;
		for ( j = i + 1; j < n; j++)
			if ( strcmp( words[k] , words[j]) > 0)
				k = j;
		char *tmp;		
		tmp = words[i];
		words[i] = words[k];
		words[k] = tmp;
	}
	
	puts("\nThe sorted:");
	for( i = 0; i < n; i++)
		puts( words[i] );
	
	return 0;
}
