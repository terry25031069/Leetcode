// https://leetcode.com/problems/leaf-similar-trees

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
    void dfs(TreeNode* root, vector<int> &ans){
        if(root->left) dfs(root->left, ans);
        if(root->right) dfs(root->right, ans);
        if(!root->left && !root->right) ans.push_back(root->val); 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>d1, d2;
        dfs(root1, d1), dfs(root2, d2);
        if(d1.size() != d2.size()) return false;
        for(int i: d1) cout << i << ' '; cout << endl;
        for(int i: d2) cout << i << ' '; cout << endl;
        for(int i = 0; i < d1.size(); i++){
            if(d1[i] != d2[i]) return false;
        }
        return true;
    }
};