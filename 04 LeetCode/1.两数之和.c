/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *values;
    i = 0;
    j = 0;
    for(i = 0; i < numsSize; i++){
        for(j = i+1; j < numsSize; j++){
            if(nums[i]+nums[j] == target)
            {
                values = (int*)malloc(sizeof(int)*2);
                values[0] = i;
                values[1] = j;
                *returnSize = 2;
                return values;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
// @lc code=end

