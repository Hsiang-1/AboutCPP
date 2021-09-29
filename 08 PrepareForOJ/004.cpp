#include <iostream> 
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct Student {
	int order;
	string name;
	int score;
};

Student arr[MAXN];

bool compare1( Student x, Student y)
{
	if( x.score == y.score)
		return x.order < y.order;
	else
		return x.score > y.score; 
}

bool compare2( Student x, Student y)
{
	if( x.score == y.score)
		return x.order < y.order;
	else
		return x.score < y.score; 
}



int main (void)
{
	int n;
	int way;
	scanf("%d%d", &n, &way);
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].name >> arr[i].score;
		arr[i].order = i;
	}
	
	if (way == 0)
		sort(arr, arr+n, compare1);
	else
		sort(arr, arr+n, compare2);
		
	for(int i = 0; i < n; i++)
		cout << arr[i].name << " " << arr[i].score << endl;
	
	return 0;
}


