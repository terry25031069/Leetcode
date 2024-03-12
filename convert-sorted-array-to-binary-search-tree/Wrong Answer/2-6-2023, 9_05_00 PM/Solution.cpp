// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int idx = nums.size() / 2;
        TreeNode *ori = new TreeNode(nums[idx]), *ans = ori;
        for(int i = idx - 1; i >= 0; i--){
            ans->left = new TreeNode(nums[i]);
            ans = ans->left;
        }
        ans = ori;
        for(int i = idx + 1; i < nums.size(); i++){
            ans->right = new TreeNode(nums[i]);
            ans = ans->right;
        }
        return ori;
    }
};