// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val) return root;
        int m = root->val, l = p->val, r = q->val;
        if(l > r) swap(l, r);
        if(l < root->val && root->val < r) return root;
        else if(r < root->val) return lowestCommonAncestor(root->left, p, q);
        else if(root->val < l) return lowestCommonAncestor(root->right, p, q);
        else return NULL; 
    }
};