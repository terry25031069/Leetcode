// https://leetcode.com/problems/find-duplicate-subtrees

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
    map<string, int> m;
    vector<TreeNode*> ans;
    string dfs(TreeNode* root){
        if(!root){
            return "X";
        }else{
            string s = dfs(root->left) + "/" + dfs(root->right) + "/" + to_string(root->val);
            m[s]++;
            if(m[s] == 2)ans.push_back(root);
            return s;
        }
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};