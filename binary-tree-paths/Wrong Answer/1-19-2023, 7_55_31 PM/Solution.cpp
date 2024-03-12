// https://leetcode.com/problems/binary-tree-paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root){
            string s = ""; s += root->val + '0';
            auto l = binaryTreePaths(root->left);
            auto r = binaryTreePaths(root->right);
            if(l.size() + r.size() == 0) return {s};
            for(auto tmps: l) ans.push_back(s + "->" + tmps);
            for(auto tmps: r) ans.push_back(s + "->" + tmps);
        }
        return ans;
    }
};