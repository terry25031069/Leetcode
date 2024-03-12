// https://leetcode.com/problems/even-odd-tree

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
    vector<vector<int>> tree;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(tree.size() == level){
            tree.push_back({});
        }
        tree[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    bool isEvenOddTree(TreeNode* root) {
        dfs(root, 0);
        for(int i = 0; i < tree.size(); i++){
            if(i&1) tree[i].push_back(0);
            else tree[i].push_back(1000001);
        }
        for(int i = 0; i < tree.size(); i++){
            for(int j = 0; j < tree[i].size() - 1; j++){
                if((i & 1) ^ !(tree[i][j] & 1)) return false;
                if((!(i & 1)) && (tree[i][j] >= tree[i][j+1]) || (i & 1) && (tree[i][j] <= tree[i][j+1])){
                    return false;
                }
            }
        }
        return true;
    }
};