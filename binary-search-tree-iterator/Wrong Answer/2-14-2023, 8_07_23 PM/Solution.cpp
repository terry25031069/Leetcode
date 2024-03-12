// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
public:
    int idx = -1;
    vector<int> v;
    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            v.push_back(root->val);
            dfs(root->right);
        }
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }

    int next() {
        idx++;
        return v[idx];
    }
    
    bool hasNext() {
        return idx < v.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */