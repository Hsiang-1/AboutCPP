/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ret = malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i) {
        ret[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}

// @lc code=end

