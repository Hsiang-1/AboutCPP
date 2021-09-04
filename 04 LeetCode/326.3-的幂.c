/*
 * @lc app=leetcode.cn id=326 lang=c
 *
 * [326] 3的幂
 */

// @lc code=start


bool isPowerOfThree(int n){
    if ( 1 == n) return true;
    if ( n <= 2) return false;
    while(n%3 == 0)
    {
        if (3==n)
            return true;
        else
            n /= 3;
    }
    return false;
}
// @lc code=end

