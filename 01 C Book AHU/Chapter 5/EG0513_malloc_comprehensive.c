// Program: EG0513.c
// Description: MALLOC

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAXLENGTH 30


int main ( void )
{
	char tmp[MAXLENGTH], **words;
	short i, j, k, n = 5;
	
	printf(" input n: ");
	scanf("%d", &n);
	
	// pointer is better than array in mallocate memory dynamically
	// the difference of **words and words[][]
	if (  (words = (char **) malloc( sizeof( char * ) * n)) == NULL )
	{
		printf("memory allocation failed!");
		return 1;
	}
	
	for ( i = 0; i < n; i++)
	{
		printf(" input word %d : ", i+1);
		scanf("%s", tmp);
		
		if( ( *(words+i) = (char * ) malloc( sizeof(char) * (strlen(tmp) + 1) ) ) == NULL )
		{
			printf("word %d memory allocation failed!", i);
			return 1;
		}
		
		strcpy( *(words+i), tmp);
		
	}
	
	for ( i = 0; i < n - 1; i++)
	{
		k = i;
		
		// selection sort
		for ( j = i + 1; j < n; j++)
			if ( strcmp( words[k] , words[j]) > 0)
				k = j;
		
		if ( k != i)
		{
			char *tmp;
			tmp = words[i];
			words[i] = words[k];
			words[k] = tmp;
		}
		
	} 
	
	printf("\n sorted: \n");
	for ( i = 0; i < n; i++)
		puts( words[i] );
	
	free(words);
	
	return 0;
}
