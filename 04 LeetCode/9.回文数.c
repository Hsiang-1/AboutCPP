/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start


bool isPalindrome(int x){
    int a = x;
    int b;

    if(x < 0 )
        return false;

    if(x<10) return true;

    while (a != 0) {
        if (b < INT_MIN / 10 || b > INT_MAX / 10) {
            return false;
        }
        int digit = a % 10;
        a /= 10;
        b = b * 10 + digit;
    }
    if(b==x)
        return true;
    return false;
    
}
// @lc code=end

