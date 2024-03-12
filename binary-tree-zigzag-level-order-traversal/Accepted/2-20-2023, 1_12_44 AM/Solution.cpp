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
    stack<TreeNode*> s;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return ans;
        int dir = 1;
        s.push(root);
        while(!s.empty()){
            ans.push_back({});
            stack<TreeNode*> tmp;
            int n = s.size();
            for(int i = 0; i < n; i++){
                auto t = s.top(); s.pop(); 
                ans.back().push_back(t->val);
                if(!dir && t->right) tmp.push(t->right);
                if(t->left) tmp.push(t->left);
                if(dir && t->right) tmp.push(t->right);
            }
            s = tmp;
            dir = 1 - dir;
        }   
        return ans;
    }
};