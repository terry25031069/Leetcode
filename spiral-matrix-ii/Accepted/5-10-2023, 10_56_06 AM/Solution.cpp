// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> ans;
    bool chk(int x, int y, int n){
        if(x < 0 || x >= n || y < 0 || y >= n) return false;
        if(ans[x][y] != -1) return false;
        return true;
    }
    vector<vector<int>> generateMatrix(int n) {
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, cur = 1, dir = 0;
        ans.resize(n, vector<int>(n, -1));
        while(cur < n * n + 1){
            ans[x][y] = cur++;
            if(chk(x + dx[dir], y + dy[dir], n) == 0){
                dir = (dir + 1) % 4;
            }
            x += dx[dir], y += dy[dir];
        }
        return ans;
    }
};