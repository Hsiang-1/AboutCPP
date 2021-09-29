#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main (void)
{
	int n;
	int nums[10000];
	int out = 0;			// 最大高度差
	int min = 0;			// 当前最小高度
	int max = 0;			// 下一个最大高度 
	
	
	while (scanf("%d", &n) != EOF) {
	
	min = 0;max = 0; out = 0;
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &nums[i]);
		
		if(i == 0)
		{
			min = nums[0];
			max = nums[0];
			continue;
		}
		
		if(nums[i] < max)
		{
			max = nums[i];
			min = nums[i];
		}
			
		if(nums[i] >= max)
		{
			max = nums[i];
			if(out < (max-min) )
				out = max - min;
		}
		
	}
	
	printf("%d\n", out);
	
	}
	
	return 0;
}

