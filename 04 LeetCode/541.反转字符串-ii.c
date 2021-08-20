/*
 * @lc app=leetcode.cn id=541 lang=c
 *
 * [541] 反转字符串 II
 */

// @lc code=start

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char *begin, char *end){
    while(begin < end){
        swap(begin++, --end);
    }
}

int min ( int a, int b ){
    return a < b ? a : b;
}

char * reverseStr(char * s, int k){
    int len = strlen(s);
    for ( int i = 0; i < len; i += 2*k ){
        reverse(&s[i], &s[(min( len, i+k))]);
    }
    return s;
}
// @lc code=end

