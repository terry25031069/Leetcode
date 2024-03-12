// https://leetcode.com/problems/check-knight-tour-configuration

class Solution {
public:
    int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    bool checkValidGrid(vector<vector<int>>& grid) {
        int x = 0, y = 0, n = grid.size(), cnt = 0;
        if(grid[x][y]) return false;
        while(cnt < n * n - 1){
            int flag = 0;
            for(int k = 0; k < 8; k++){
                int tx = x + dx[k], ty = y + dy[k];
                if(tx > -1 && tx < n && ty > -1 && ty < n){
                    if(grid[tx][ty] == cnt + 1){ cnt++, flag = 1, x = tx, y = ty; break;}
                }
            }
            //cout << cnt << ' ' << x << ' ' << y << endl;
            if(!flag) return false;
        }
        return true;
    }
};