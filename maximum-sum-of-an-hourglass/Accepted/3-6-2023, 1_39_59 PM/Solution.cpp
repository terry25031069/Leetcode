// https://leetcode.com/problems/maximum-sum-of-an-hourglass

class Solution {
public:
    int hg(int i, int j, vector<vector<int>> &grid){
        int ans = 0;
        for(int dx = 0; dx < 3; dx++){
            for(int dy = 0; dy < 3; dy++){
                ans += grid[dx+i][dy+j];
            }
        }
        return ans - grid[i+1][j] - grid[i+1][j+2];
    }
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size() - 2; i++){
            for(int j = 0; j < grid[0].size() - 2; j++){
                ans = max(ans, hg(i, j, grid));
            }
        }
        return ans;
    }
};