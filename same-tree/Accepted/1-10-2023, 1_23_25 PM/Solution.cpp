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
    vector<int> dfs(TreeNode* p){
        vector<int>ans, l, r;
        if(p)ans.push_back(p->val);
        else return {};
        if(p->left) l = dfs(p->left), ans.insert(ans.end(), l.begin(), l.end());
        else ans.push_back(1e5);
        if(p->right) r = dfs(p->right), ans.insert(ans.end(), r.begin(), r.end());
        else ans.push_back(1e5);
        return ans;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>porder = dfs(p);
        vector<int>qorder = dfs(q);
        return porder == qorder;
    }
};