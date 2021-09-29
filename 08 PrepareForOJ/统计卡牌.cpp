#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

using namespace std;

int main (void)
{
	int stringlen = 0;
	int sum = 0;
	char str[100];
	
	scanf("%d", &stringlen);
	while(stringlen--)
	{
		cin >> str;
		for(int i=0; i<strlen(str); i++)
		{
			switch(str[i]){
				case 'J':
					sum += 1;
					break;
				case 'Q':
					sum += 2;
					break;
				case 'K':
					sum += 3;
					break;
				case 'A':
					sum += 4;
					break;
				default:
					break;
			}
		}
	}
	
	printf("%d", sum);
} 
