#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<long long> nums;

int main (void)
{
	int n;
	cin >> n;
	
	while(n--)
	{
		long long int a;
		cin >> a;
		nums.push(a);
	}
	
	while(nums.size())
	{
		cout << nums.top() << " ";
		nums.pop();
	}
	
	return 0;
}

