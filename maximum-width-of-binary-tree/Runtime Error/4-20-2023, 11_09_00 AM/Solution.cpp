// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    vector<vector<int>> v;
    void dfs(TreeNode* root, int n, int lvl){
        if(v.size() <= lvl) v.push_back({});
        if(root){
            v[lvl].push_back(n);
            dfs(root->left, n * 2, lvl + 1);
            dfs(root->right, n * 2 + 1, lvl + 1);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
       dfs(root, 1, 0);
       int ans = 0;
       for(auto sv: v){
           if(sv.size()) ans = max(ans, *max_element(sv.begin(), sv.end()) - *min_element(sv.begin(), sv.end()));
       }
       return ans + 1;
    }
};