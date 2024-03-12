// https://leetcode.com/problems/construct-quad-tree

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(int sz, int cx, int cy, vector<vector<int>>& grid){
        if(sz == 1){
            return new Node(grid[cx][cy], true);
        }
        Node* tL = dfs(sz/2, cx, cy, grid);
        Node* tR = dfs(sz/2, cx, cy+sz/2, grid);
        Node* bL = dfs(sz/2, cx+sz/2, cy, grid);
        Node* bR = dfs(sz/2, cx+sz/2, cy+sz/2, grid);
        bool tmp = (tL->val == tR->val) && (tR->val == bL->val) && (bL->val == bR->val);
        tmp = tmp && tL->isLeaf && tR->isLeaf && bL->isLeaf && bR->isLeaf;
        if(tmp) return new Node(grid[cx][cy], true);
        return new Node(0, tmp, tL, tR, bL, bR);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(n, 0, 0, grid);
    }
};