// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool ans = 1;
    vector<vector<int>> v;
    void dfs(TreeNode* root, int depth){
        if(depth >= v.size()) v.push_back({});
        if(root){
            if(root->val){
                if(v[depth].size() > 0 && v[depth].back() == -1){ans = 0; return;}
                v[depth].push_back(root->val);
            }
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        } else v[depth].push_back(-1);
    }
    bool isCompleteTree(TreeNode* root) {
        dfs(root, 0);
        // for(auto sv: v){
        //     for(auto e: sv) cout << e << ' ';
        //     cout << endl;
        // }
        if(ans){
            for(int i = 0; i < v.size(); i++){
                if((1 << i) != v[i].size()){
                    if(i != v.size() - 1) return false;
                }
            }
            return true;
        }
        else return false;
    }
};