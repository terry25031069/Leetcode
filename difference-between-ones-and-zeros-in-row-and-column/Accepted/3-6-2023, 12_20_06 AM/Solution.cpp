// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) row[i]++, col[j]++;
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = 2 * (row[i] + col[j]) - m - n;
            }
        }
        return ans;
    }
};