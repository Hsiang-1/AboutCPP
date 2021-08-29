/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void PreorderTraversal(struct TreeNode *root, int*ans,int*returnSize){
    if(root != NULL){
        ans[*returnSize] = root->val;
        (*returnSize) += 1;
        PreorderTraversal(root->left, ans, returnSize);
        PreorderTraversal(root->right, ans, returnSize);
    }
}


int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    PreorderTraversal(root, ans, returnSize);
    return ans;
}
// @lc code=end

