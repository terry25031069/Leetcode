// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    int ans = 0;
    void dfs(TreeNode* root, string s){
        if(!root->left && !root->right){
            s += char(root->val + '0');
            ans += stoi(s);
        }
        else{
            if(root->left) dfs(root->left, s + char(root->val + '0'));
            if(root->right) dfs(root->right, s + char(root->val + '0'));
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};