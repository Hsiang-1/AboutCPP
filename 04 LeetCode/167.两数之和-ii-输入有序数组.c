/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 0;
    int *ans = (int *)malloc(sizeof(int) * 2);
    int i, j;
    for (i = 0;i<numbersSize;i++)
    {
        for(j = i+1;j<numbersSize;j++)
        {
            if((numbers[j]+numbers[i])==target)
            {
                *returnSize = 2;
                ans[0] = i + 1;
                ans[1] = j + 1;
                return ans;
            }
            if((numbers[j]+numbers[i])>target)
                break;
        }
    }
    ans[0] = -1;
    ans[1] = -1;
    return ans;
}
// @lc code=end

