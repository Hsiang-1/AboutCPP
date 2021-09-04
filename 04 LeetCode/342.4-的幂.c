/*
 * @lc app=leetcode.cn id=342 lang=c
 *
 * [342] 4的幂
 */

// @lc code=start


bool isPowerOfFour(int n){
    if ( 1 == n) return true;
    if ( n <= 3) return false;
    while(n%4 == 0)
    {
        if (4==n)
            return true;
        else
            n /= 4;
    }
    return false;
}
// @lc code=end

