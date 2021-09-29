#include <iostream>
#include <cstdio>
#include <stack>
#include <string> 

using namespace std;

stack<int> sta;

int main (void)
{
	string str;
	getline( cin, str);
	
	string ans(str.size(), ' ');
	
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == '(')
		{
			sta.push(i);
		}
		
		if(str[i] == ')')
		{
			if(sta.empty())
				ans[i] = '?';
			else
				sta.pop();
		}
		
	}
	
	while(sta.size())
	{
		ans[sta.top()] = '$';
		sta.pop();
	} 
	
	
	cout << ans << endl;
	
	
	return 0;
}

