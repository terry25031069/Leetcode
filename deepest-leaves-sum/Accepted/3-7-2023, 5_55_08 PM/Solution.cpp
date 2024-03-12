// https://leetcode.com/problems/deepest-leaves-sum

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
    vector<int> v;
    void dfs(TreeNode* root, int lvl){
        if(root){
            if(lvl >= v.size()) v.push_back(0);
            v[lvl] += root->val;
            dfs(root->left, lvl+1);
            dfs(root->right, lvl+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return v.back();
    }
}; 