// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> ans;
    void dfs(TreeNode* root, int depth){
        if(root){
            if(ans.size() == depth) ans.push_back(-2147483648);
            ans[depth] = max(ans[depth], root->val);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};