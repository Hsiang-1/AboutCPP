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
	int out = 0;			// ���߶Ȳ�
	int min = 0;			// ��ǰ��С�߶�
	int max = 0;			// ��һ�����߶� 
	
	
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

