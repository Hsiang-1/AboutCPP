#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string divide(string str, int x)
{
	int remainder = 0;
	for (int i = 0; i < str.size(); i ++)
	{
		int current = remainder * 10 + str[i] - '0';
		str[i] = current / x + '0';
		remainder = current % x;
	}
	int pos = 0;
	while( str[pos] == '0')
	{
		pos++;
	}
	return str.substr(pos);
}

int main(void)
{
	string str;
	
	while(cin >> str)
	{
		vector<int> binary;
		while( str.size())
		{
			int last = str[str.size() - 1] - '0';
			binary.push_back(last % 2);
			str = divide(str, 2);
		}
		for( int i = binary.size() - 1; i>=0; i--)
			cout << binary[i];
	
		cout << endl;
	}
	
	return 0;
}


