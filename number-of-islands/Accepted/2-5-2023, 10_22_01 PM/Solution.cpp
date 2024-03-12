// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '0';
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for(int k = 0; k < 4; k++){
            if(i + dx[k] > -1 && i + dx[k] < grid.size() &&
               j + dy[k] > -1 && j + dy[k] < grid[0].size() &&
               grid[i + dx[k]][j + dy[k]] == '1'){
                dfs(i + dx[k], j + dy[k], grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};