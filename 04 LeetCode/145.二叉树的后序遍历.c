/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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

void PostorderTraversal(struct TreeNode *root, int *ans, int * returnSize){
    if(root != NULL){
        PostorderTraversal(root->left, ans, returnSize);
        PostorderTraversal(root->right, ans, returnSize);
        ans[* returnSize] = root->val;
        *returnSize += 1;
    }
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    PostorderTraversal(root, ans, returnSize);
    return ans;
}
// @lc code=end

