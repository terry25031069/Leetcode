// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree

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
    vector<int64_t> sum;
    void dfs(TreeNode* root, int lvl){
        if(sum.size() <= lvl) sum.push_back(0);
        if(root){
            sum[lvl] += root->val;
            dfs(root->left, lvl+1);
            dfs(root->right, lvl+1);
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);
        if(k > sum.size()) return -1;
        priority_queue<int> q;
        for(int i: sum) q.push(i);
        k--;
        while(k--) q.pop();
        return q.top();
    }
}; 