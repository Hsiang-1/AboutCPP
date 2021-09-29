#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 100;


int main (void)
{
	string str1, str2;
	while(cin >> str1 >> str2)
	{
		int answer = 0;
		for(int i = 0; i < str1.size() ; i++)
			for( int j = 0; j < str2.size() ; j ++)
				answer += (str1[i] - '0') * (str2[j] - '0');
		
		cout << answer << endl;
	}
	
	
	return 0;
}

