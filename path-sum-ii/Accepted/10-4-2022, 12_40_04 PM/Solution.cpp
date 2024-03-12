// https://leetcode.com/problems/path-sum-ii

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
    vector<int> path;
    vector<vector<int>> ans; 
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return ans;
        cout << root->val << ' ' << targetSum << endl;
        cout << "path: ";
        for(int i = 0; i < path.size(); i++)
            cout << path[i] << " \n"[i == path.size() - 1];
        if(targetSum == root->val && root->left == NULL && root->right == NULL){
            path.emplace_back(root->val);
            ans.emplace_back(path);
            path.pop_back();
        }
        if(root->left != NULL){
            path.emplace_back(root->val);
            pathSum(root->left, targetSum - root->val);
            path.pop_back();
        }
        if(root->right != NULL){
            path.emplace_back(root->val);
            pathSum(root->right, targetSum - root->val);
            path.pop_back();
        }
        return ans;
    }
};