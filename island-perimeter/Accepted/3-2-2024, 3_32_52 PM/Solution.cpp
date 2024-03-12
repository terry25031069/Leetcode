// https://leetcode.com/problems/island-perimeter

class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1 ,0};
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    int tmpans = 4;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if(nx > -1 && nx < grid.size() && ny > -1 && ny < grid[0].size() && grid[nx][ny] == 1) tmpans--;
                    }
                    ans += tmpans;
                }
            }
        }
        return ans;
    }
};