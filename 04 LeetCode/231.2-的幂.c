/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2 的幂
 */

// @lc code=start


bool isPowerOfTwo(int n){
    if (n <= 0) return false;
    if (n == 1) return true;
    while( n%2 == 0)
    {
        if(n == 2)
            return true;
        else
            n /= 2;
    }
    return false;
}
// @lc code=end

