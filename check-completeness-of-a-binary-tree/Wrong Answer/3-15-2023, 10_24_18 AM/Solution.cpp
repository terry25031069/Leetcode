// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool ans = 1;
    int dfs(TreeNode* root, int depth){
        if(root){
            if(!root->left && !root->right) return depth;
            if(!root->left && root->right){
                ans = 0;
                return 0;
            }
            int ldepth = dfs(root->left, depth+1);
            int rdepth = -1;
            if(root->right) rdepth = dfs(root->right, depth+1);
            if(ldepth < rdepth){
                ans = 0;
                return 0;
            }
            return max(ldepth, rdepth);
        }
        return 0;
    }
    bool isCompleteTree(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};