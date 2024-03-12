// https://leetcode.com/problems/check-if-matrix-is-x-matrix

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if((i == j || i == grid.size() - 1 - j) && grid[i][j] || i - j && !grid[i][j]) continue;
                return false; 
            }
        }
        return true;
    }
};