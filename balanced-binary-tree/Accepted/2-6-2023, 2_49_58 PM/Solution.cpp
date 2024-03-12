// https://leetcode.com/problems/balanced-binary-tree

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
    int depth(TreeNode* root){
        if(root){
            return max(depth(root->left), depth(root->right)) + 1;
        }else return 0;
    }
    bool isBalanced(TreeNode* root) {
        if(root){
            if(abs(depth(root->right) - depth(root->left)) < 2){
                return isBalanced(root->right) && isBalanced(root->left);
            }
            return false;
        }
        return true;
    }
};