#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	string aaa= "dbegfca";
	int position = 2;
	
	cout << aaa.substr(0,position) << endl;
	cout << aaa.substr(position, aaa.size() - position - 1) << endl;
	cout << aaa.substr(position + 1) << endl;
	
	return 0;
}
