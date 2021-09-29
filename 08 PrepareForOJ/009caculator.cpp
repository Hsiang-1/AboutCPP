#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <stack>

using namespace std;

int priority(char c)
{
	switch(c){
		case '#':
			return 0;
		case '$':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		default:
			return -1;
	}
}

double getnumber(string str, int& index)
{
	double number = 0;
	while(isdigit(str[index]))
	{
		number = number * 10 + str[index] - '0';
		index += 1;
	}
	return number;
}

double calculate(double x, double y, char op)
{
	switch(op)
	{
		case '+':
			return x+y;
		case '-':
			return x-y;
		case '*':
			return x*y;
		case '/':
			return x/y;
	}
}


int main (void)
{
	string str;
	while(getline(cin, str))
	{
		if(str == "0")
			break;
		
		int index = 0;
		stack<char> oper;
		stack<double> data;
		str += '$';
		oper.push('#'); 
		
		while(index < str.size())
		{
			if (str[index] == ' ')
				index ++;
			else if(isdigit(str[index]))
				data.push(getnumber(str, index));
			else
			{
				if(priority(oper.top()) < priority(str[index]))
				{
					oper.push(str[index]);
					index++;
				}
				else
				{
					double y = data.top();
					data.pop();
					double x = data.top();
					data.pop();
					data.push(calculate( x, y, oper.top()));
					oper.pop();
				} 
			}
		}
		
		printf("%.2f\n", data.top());		
	}
	
	return 0;
}

