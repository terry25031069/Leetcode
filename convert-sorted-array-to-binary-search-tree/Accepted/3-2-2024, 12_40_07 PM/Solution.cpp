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
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);
        int n = nums.size();
        TreeNode* root = new TreeNode(nums[n / 2]);
        auto ll = nums.begin(), lr = nums.begin() + n / 2;
        auto rl = nums.begin() + n / 2 + 1, rr = nums.end();
        vector<int> newL(ll, lr), newR(rl, rr);
        root->left = sortedArrayToBST(newL);
        root->right = sortedArrayToBST(newR);
        return root;
    }
};