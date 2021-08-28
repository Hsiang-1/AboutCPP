/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = 0;
    int flag = 0;
    digits[digitsSize - 1] += 1;
    for (i = digitsSize - 1; i > 0;i--){
        if(digits[i]==10){
            digits[i - 1] += 1;
            digits[i] = 0;
        }
        else
            break;
    }
    (* returnSize) = digitsSize;
    if(digits[0] == 10){
        (* returnSize) += 1;
        digits[0] = 0;
        flag = 1;
    }
    int *ans = (int *) malloc(sizeof(int)*(*returnSize));

    if(flag==1){
        ans[0] = 1;
        for (i = 1;i < *returnSize; i++){
            ans[i] = digits[i - 1];
        }
    }
    else{
        for (i = 0;i<*returnSize;i++){
            ans[i] = digits[i];
        }
    }

    return ans;
}
// @lc code=end

