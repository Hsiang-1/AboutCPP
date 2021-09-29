#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	
	int arr[200][200];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	int count = 0;
	
	for(int l = min(n,m); l >= 2; l--)
	{
		int now = 0;
		
		for(int b = 0; b <= m-l; b++)
			for(int a = 0; a<= n-l; a++)
			{				
				int sum = 0;
				for(int i = 0; i < l; i++)
					for(int j = 0; j <= i; j++)
					{
						sum += arr[a+i][b+j];
					}
				if(sum >= k)
					now += 1;
				
				sum = 0;
				for(int i = 0; i < l; i++)
					for(int j = 0; j <= l-1-i; j++)
					{
						sum += arr[a+i][b+j];
					}
				if(sum >= k)
					now += 1;
				
				sum = 0;
				for(int i = 0; i < l; i++)
					for(int j = l-1; j >= l-1-i; j--)
					{
						sum += arr[a+i][b+j];
					}
				if(sum >= k)
					now += 1;
				
				sum = 0;
				for(int i = 0; i < l; i++)
					for(int j = i; j <= l-1; j++)
					{
						sum += arr[a+i][b+j];
					}
				if(sum >= k)
					now += 1;
			}
		
		count += now; 
	}
	
	cout << count << endl;
}
