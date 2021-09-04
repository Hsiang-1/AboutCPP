/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 */

// @lc code=start


void moveZeroes(int* nums, int numsSize){
    int i, zeronum;
    zeronum = 0;
    for (i = 0; i< numsSize; i++)
    {
        nums[i-zeronum] = nums[i];
        if(nums[i] == 0)
        {
            zeronum++;
        }
    }
    for (i=numsSize-zeronum; i<numsSize; i++)
        nums[i] = 0;
}
// @lc code=end

