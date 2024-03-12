// https://leetcode.com/problems/same-tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(p->val && !q || !p && q->val || p->val != q->val) return false;
        if(!p->left && q->left || p->left && !q->left) return false;
        if(!p->right && q->right || p->right && !q->right) return false;
        bool ans = 1;
        if(p->left && q->left) ans &= isSameTree(p->left, q->left);
        if(p->right && q->right) ans &= isSameTree(p->right, q->right);
        return ans;
    }
};