// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(Node* root, int lvl){
        if(ans.size() <= lvl) ans.push_back({});
        ans[lvl].push_back(root->val);
        auto a = root->children;
        for(int i = 0; i < a.size(); i++){
            dfs(a[i], lvl + 1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(root)dfs(root, 0);
        return ans;
    }
};