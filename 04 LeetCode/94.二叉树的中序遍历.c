/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
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

void InorderTraversal (struct TreeNode *root, int *ans, int * returnSize){
    if(root != NULL){
        InorderTraversal(root->left,ans,returnSize);
        ans[* returnSize] = root->val;
        *returnSize += 1;
        InorderTraversal(root->right,ans,returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *ans = (int *)malloc(sizeof(int)*100);
    InorderTraversal(root, ans, returnSize);
    return ans;
}
// @lc code=end

