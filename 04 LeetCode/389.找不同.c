/*
 * @lc app=leetcode.cn id=389 lang=c
 *
 * [389] 找不同
 */

// @lc code=start


char findTheDifference(char * s, char * t){
    int a;
    int i;
    int aaa[26] = {0};
    int bbb[26] = {0};
    a = strlen(s);

    if(a==0)
        return t[0];

    for (i = 0; i < a; i++)
    {
        aaa[((int)(s[i])) - 97] += 1;
        bbb[((int)(t[i])) - 97] += 1;
    }
    bbb[((int)(t[i])) - 97] += 1;

    for (i = 0; i < 26; i++)
    {
        if(aaa[i]!=bbb[i])
            return (char)(97 + i);
    }

    return 0;
}
// @lc code=end

