// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    int m, n, ans = 0, cnt = 0;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
    bool dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(!grid[i][j]) return true;
        grid[i][j] = 0, cnt++;
        bool ans = 1;
        for(int k = 0; k < 4; k++){
            bool res = dfs(i + dx[k], j + dy[k], grid);
            ans &= res;
        }
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    cnt = 0;
                    bool tmp = dfs(i, j, grid);
                    if(tmp) ans += cnt;
                }
            }
        }
        return ans;
    }
};