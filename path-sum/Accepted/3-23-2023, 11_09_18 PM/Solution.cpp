// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        cout << root->val << ' ' << targetSum << endl;
        if(targetSum == root->val && root->left == NULL && root->right == NULL) return true;
        bool tmp1, tmp2;
        tmp1 = tmp2 = false;
        if(root->left != NULL){
            tmp1 = hasPathSum(root->left, targetSum - root->val);
        }
        if(root->right != NULL){
            tmp2 = hasPathSum(root->right, targetSum - root->val);
        }
        return tmp1 || tmp2;
    }
};