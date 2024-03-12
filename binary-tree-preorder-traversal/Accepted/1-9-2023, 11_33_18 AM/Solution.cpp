// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans, left, right;
        if(!root) return ans;
        ans.push_back(root->val);
        if(root->left) left = preorderTraversal(root->left);
        if(root->right) right = preorderTraversal(root->right);
        if(left.size()) ans.insert(ans.end(), left.begin(), left.end());
        if(right.size()) ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};