// https://leetcode.com/problems/validate-binary-search-tree

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
    vector<int> ansa;
    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            ansa.push_back(root->val);
            dfs(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        auto ansb = ansa;
        sort(ansb.begin(), ansb.end());
        for(int i = 0; i < ansb.size() - 1; i++){
            if(ansb[i] == ansb[i + 1]) return false;
        }
        // for(int i: ansa) cout << i << ' '; cout << endl;
        // for(int i: ansb) cout << i << ' '; cout << endl;
        return ansb == ansa;
    }
};