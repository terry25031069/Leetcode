// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    void dfs(TreeNode* root, vector<int> &v){
        if(root){
            dfs(root->left, v);
            v.push_back(root->val);
            dfs(root->right, v);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        sort(v.begin(), v.end());
        int ans = 1e8;
        for(int i = 0; i < v.size() - 1; i++){
            ans = min(ans, abs(v[i] - v[i+1]));
        }
        return ans;
    }
};