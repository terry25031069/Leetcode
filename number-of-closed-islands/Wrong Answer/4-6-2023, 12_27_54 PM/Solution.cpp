// https://leetcode.com/problems/number-of-closed-islands

class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int dfs(int i, int j, vector<vector<int>>& grid){
        if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && !grid[i][j]){
            return false;
        }
        grid[i][j] = 1;
        int ans = 1;
        for(int k = 0; k < 4; k++){
            int tx = i + dx[k], ty = j + dy[k];
            if(tx > 0 && ty > 0 && tx < n && ty < n && !grid[tx][ty]){
                ans |= dfs(tx, ty, grid);
                if(!ans) return false;
            }
        }
        return true;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j] && dfs(i, j, grid)){
                    ans++;
                }
            }
        }
        return ans;
    }
};