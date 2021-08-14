// Program: EG0702.c
// Description: ... 

#include <stdio.h>

typedef struct
{
	char point;
	char face;
} Card;

int main ( int argc , char * argv[] )
{
	char *faces[4] = { "\x3", "\x4", "\x5", "\x6"};
	char *points[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	
	int card, i, j;
	Card Player[4][13];
	
	for (card = 0; card < 52; card ++)
	{
		i = card % 4;
		j = card / 4;
		Player[i][j].face = i;
		Player[i][j].point = j;
	}
	
	printf("Player1\t\tPlayer2\t\tPlayer3\t\tPlayer4\n");
	
	for ( j = 0; j < 13; j ++)
	{
		for ( i = 0; i < 4; i ++)
			printf(" %-2s %-4s\t", faces[Player[i][j].face], points[Player[i][j].point]);
		printf("\n");
	}
	
	
	return 0;
}





