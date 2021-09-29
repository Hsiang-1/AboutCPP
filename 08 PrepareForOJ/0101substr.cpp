#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main (void)
{
	string str;
	while( cin >> str)
	{
		map<string, int> number;
		for(int i = 0; i <= str.size(); i++)
		{
			for(int j = 0; j < i; j++)
			{
				string key = str.substr(j, i-j);
				number[key]++;
			}
		}
		
		map<string, int>::iterator it;
		for(it = number.begin(); it != number.end(); ++it)
			if( 1 < it->second)
				cout << it->first << " " << it->second << endl;
		
	}
	
	return 0;
}
