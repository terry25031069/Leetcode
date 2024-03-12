// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 1; i < n; i++){
            grid[i][0] += grid[i-1][0];
            if(grid[i][0] <= k) ans++;
        }
        for(int i = 1; i < m; i++){
            grid[0][i] += grid[0][i-1];
            if(grid[0][i] <= k) ans++;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                grid[i][j] += grid[i][j-1] + grid[i-1][j] - grid[i-1][j-1];
                if(grid[i][j] <= k) ans++;
                else break;
            }
        }
        // for(auto v: grid){
        //     for(auto i: v) cout << i << ' ';
        //     cout << endl;
        // }
        return ans + (grid[0][0] <= k);
    }
};