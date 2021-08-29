/*
 * @lc app=leetcode.cn id=263 lang=c
 *
 * [263] 丑数
 */

// @lc code=start


bool isUgly(int n){
    int flag = 1;

    if(n<=0){
        return false;
    }

    while( n != 1 )
    {
        if(flag != 1){
            return false;
        }
        flag = 0;
        if(n % 5 == 0){
            n /= 5;
            flag = 1;
        }
        if(n % 2 == 0){
            n /= 2;
            flag = 1;
        }
        if(n % 3 == 0){
            n /= 3;
            flag = 1;
        }
    }
    return true;
}
// @lc code=end

