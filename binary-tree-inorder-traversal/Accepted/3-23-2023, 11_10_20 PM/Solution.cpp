// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> ans;
    void DFS(TreeNode* root){
        if(!root) return;
        if(root->left) DFS(root->left);
        ans.emplace_back(root->val);
        cout << root->val << ' ';
        if(root->right) DFS(root->right);
        cout << endl;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        DFS(root);
        return ans;
    }
};