#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int arr[MAXN];

bool binarysearch(int n, int target)
{
	int left = 0;
	int right = n - 1;
	while(left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] < target)
			left = middle + 1;
		else if (target < arr[middle])
			right = middle - 1;
		else
			return true;
	}
	return false;
}


int main(void)
{
	int n, m;
	while ( scanf("%d", &n) != EOF)
	{
		for( int i = 0; i < n ; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+n);
		scanf("%d", &m);
		for( int i = 0; i< m;i++)
		{
			int target;
			scanf("%d", &target);
			if( binarysearch(n, target))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	
	return 0;
}


