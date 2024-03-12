// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int area = 1; 
        grid[x][y] = 0;
        for(int k = 0; k < 4; k++){
            if(x + dx[k] >= 0 && x + dx[k] < grid.size() 
              && y + dy[k] >= 0 && y + dy[k] < grid[0].size() && grid[x+dx[k]][y+dy[k]] == 1)
            area += dfs(grid, x + dx[k], y + dy[k]);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ma = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j);
                    cout << i << ' ' << j << ' ' << area << endl;
                    if(area > ma) ma = area;
                }
            }
        }
        return ma;
    }
};