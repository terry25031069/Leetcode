// https://leetcode.com/problems/diameter-of-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLength(TreeNode *root){
        if(!root) return 0;
        return 1 + max(maxLength(root->left), maxLength(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int L = maxLength(root->left);
        int R = maxLength(root->right);
        int dL = diameterOfBinaryTree(root->left);
        int dR = diameterOfBinaryTree(root->right);
        return max(L + R, max(dL, dR));
    }
};