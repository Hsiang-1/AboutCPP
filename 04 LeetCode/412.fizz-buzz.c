/*
 * @lc app=leetcode.cn id=412 lang=c
 *
 * [412] Fizz Buzz
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char *aaa = "Fizz";
    char *bbb = "Buzz";
    char *ccc = "FizzBuzz";
    int i;
    char **ans = (char **)malloc(sizeof(char*) * n);
    *returnSize = n;

    for(i=1; i<=n; i++){
        if(i%15 == 0)
            ans[i - 1] = ccc;
        else if(i%3==0)
            ans[i - 1] = aaa;
        else if (i%5 ==0)
            ans[i - 1] = bbb;
        else
        {
            ans[i-1] = (char *)malloc(sizeof(char) * 10);
            sprintf(ans[i - 1], "%d", i);
        }
    }
    return ans;
}
// @lc code=end

