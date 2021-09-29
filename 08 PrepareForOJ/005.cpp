#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> numbere;
vector<int> numberg;

int sum( int x)
{
	int sum = 0;
	for( int i = 1; i < x; i++)
		if( x%i == 0)
			sum += i;
	return sum;
}

int main (void)
{
	for( int i = 2; i <= 60; i++)
	{
		if( i == sum(i))
			numbere.push_back(i);
		if( i < sum(i))
			numberg.push_back(i);
	}
	
	cout << "E: ";
	for( int i = 0; i < numbere.size(); i++)
		cout << numbere[i] << " ";
	cout << endl << "G: ";
	for( int i = 0; i < numberg.size(); i++)
		cout << numberg[i] << " ";
	cout << endl;
	
	return 0;
}


