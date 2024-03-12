// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    TreeNode* Root;
    bool search(TreeNode* root, int n, TreeNode* N){
        if(root){
            if(n == N->val) return false;
            if(root->val == n) return true;
            else if(root->val < n) return search(root->right, n, N);
            else search(root->left, n, N);
        }
        return false;
    }
    bool helper(TreeNode* root, int k){
        if(root){
            cout << root->val << endl;
            int ans = 0;
            ans |= search(Root, k - root->val, root);
            if(ans) return true;
            ans |= helper(root->left, k);
            if(ans) return true;
            ans |= helper(root->right, k);
            if(ans) return true;
            return false;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        Root = root;
        return helper(root, k);
    }
};