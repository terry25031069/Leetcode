// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int istart, int iend, int pstart, int pend, unordered_map<int, int>& idx){
        if(istart > iend || pstart > pend) return NULL;
        int rootVal = postorder[pend];
        TreeNode* root = new TreeNode(rootVal);
        int rootidx = idx[rootVal];
        int leftSize = rootidx - istart;
        root->left = build(inorder, postorder, istart, rootidx - 1, pstart, pstart + leftSize - 1, idx);
        root->right = build(inorder, postorder, rootidx + 1, iend, pstart + leftSize, pend - 1, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> idx;
        for(int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size()-1, idx);
    }
};