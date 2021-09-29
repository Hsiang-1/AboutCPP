#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main (void)
{
	int n, p, m;
	while(scanf("%d%d%d", &n, &p, &m))
	{
		if (n==0&&p==0&&m==0)
			break;
		
		queue<int> children;
		
		for(int i = 1; i <= n; i ++)
			children.push(i);
		
		for(int i = 1; i < p; i++)
		{
			children.push(children.front());
			children.pop();
		}
		
		while(children.size())
		{
			for(int i = 1; i < m; i ++)
			{
				children.push(children.front());
				children.pop();
			}
			printf("%d",children.front());
			if(children.size() != 1)
				cout << ',';
			children.pop();
		}
		cout << endl;
		
	}
	
	return 0;
}


