// https://leetcode.com/problems/detect-cycles-in-2d-grid

class Solution {
public:
    vector<vector<bool>> visit;
    bool dfs(int pi, int pj, int i, int j, vector<vector<char>>& grid){
        visit[i][j] = 1; 
        int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        bool ans = 0;
        for(int k = 0; k < 4; k++){
            if(i + dx[k] > -1 && i + dx[k] < grid.size() &&
               j + dy[k] > -1 && j + dy[k] < grid[0].size() && 
               !(i + dx[k] == pi && j + dy[k] == pj) && 
               grid[i][j] == grid[i + dx[k]][j + dy[k]]){
                   if(visit[i+dx[k]][j+dy[k]]) return true;
                   else{
                       ans |= dfs(i, j, i+dx[k], j+dy[k], grid);
                   }
               }
        }
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        visit.resize(grid.size(), vector<bool>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(visit[i][j] == 0){
                    bool tmp = dfs(i, j, i, j, grid);
                    if(tmp) return true;
                }
            }
        }    
        return false;
    }
};