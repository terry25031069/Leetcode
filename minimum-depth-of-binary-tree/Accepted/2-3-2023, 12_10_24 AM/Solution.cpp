// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int dfs(TreeNode* root){
        if(root){  
            int dl = dfs(root->left), dr = dfs(root->right);
            if(dl == 0 && dr == 0) return 1;
            else if(dl == 0) return dr + 1;
            else if(dr == 0) return dl + 1;
            return min(dl, dr) + 1;
        }else return 0;
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};