// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    void dfs(TreeNode* root, map<int, int> &m){
        if(root){
            m[root->val] += 1;
            dfs(root->left, m);
            dfs(root->right, m);
        }
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int> m;
        vector<int> ans;
        dfs(root, m);
        int ma = 0;
        for(auto [k, v]: m){
            if(ma < v){
                ma = v;
                ans.clear(), ans.push_back(k);
            }else if(ma == v){
                ans.push_back(k);
            }
        }
        return ans;
    }
};