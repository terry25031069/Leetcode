// https://leetcode.com/problems/validate-binary-search-tree

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
    bool BSTchk(TreeNode* grandpa, TreeNode *root, int dir){
        if(root){
            if(dir == 0){
                if(root->left && root->left->val <= root->val) return false;
                if(root->right && (root->right->val <= root->val 
                                || root->right->val >= grandpa->val)) return false;
            }else{
                if(root->right && root->right->val <= root->val) return false;
                if(root->left && (root->left->val >= root->val 
                                || root->left->val <= grandpa->val)) return false;
            }
            return BSTchk(root, root->left, 0) && BSTchk(root, root->right, 1);
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root){
            if(root->left && root->left->val >= root->val) return false;
            if(root->right && root->right->val <= root->val) return false;
            return BSTchk(root, root->left, 0) && BSTchk(root, root->right, 1);
        }
        return true;
    }
};