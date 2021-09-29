#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 100;


vector<int> my;


int main (void)

{
	for( int i=0; i<5; i++)
		my.push_back(i);
	
	my.insert(my.begin(), 3, 15);
	
	my.pop_back();
	
	for( int i=0; i<my.size(); i++)
		printf("%d ", my[i]);
	printf("\n");
	
	printf("%d\n", my[4]);
	
	return 0;
}



