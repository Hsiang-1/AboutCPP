#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

int main(void)
{
	int casenum;
	scanf("%d", &casenum);
	while( casenum-- )
	{
		string str;
		cin >> str;
		
		stack<char> brackets;
		int flag = 1;
		int flagsmall = 0; 
		
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '(')
				flagsmall = 1;
			
			if(str[i] == '{' || str[i] == '(' || str[i] == '[')
				brackets.push(str[i]);
			
			else if(str[i] == ')')
			{
				if( brackets.top() == '(')
				{
					brackets.pop();
					if(brackets.size() == 0)
						continue;
					if(brackets.top() != '[')
					{
						flag = 0;
						break;
					}
				}
				else
				{
					flag = 0;
					break;
				}
			}
			
			else if(str[i] == ']')
			{
				if( brackets.top() == '[')
				{
					brackets.pop();
					if(brackets.size() == 0)
						continue;
					if(brackets.top() != '{')
					{
						flag = 0;
						break;
					}
				}
				else
				{
					flag = 0;
					break;
				}
			}
			
			else if(str[i] == '}')
			{
				if( brackets.top() == '{')
				{
					brackets.pop();
					if(brackets.size() == 0)
						continue;
					if(brackets.top() != '(')
					{
						flag = 0;
						break;
					}
				}
				else
				{
					flag = 0;
					break;
				}
			}
	
		}
		if(flag == 1 && flagsmall == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	
	
	return 0;
} 


