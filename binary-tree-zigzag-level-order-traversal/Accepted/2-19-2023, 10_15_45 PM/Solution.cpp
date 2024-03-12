// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int lvl){
        if(root){
            if(ans.size() <= lvl) ans.push_back({});
            dfs(root->left, lvl + 1);
            ans[lvl].push_back(root->val);
            dfs(root->right, lvl + 1);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        for(int i = 0; i < ans.size(); i++){
            if(i & 1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};