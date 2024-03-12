// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, Node*> m;
    Node* dfs(Node* node){
        Node* ans = NULL;
        if(node){
            ans = new Node(node->val);
            m[node->val] = ans;
            for(auto p: node->neighbors){
                if(!m[p->val]) ans->neighbors.push_back(dfs(p));
                else ans->neighbors.push_back(m[p->val]);
            }
        }
        return ans;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};