// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int step[101][101] = {};
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                step[i][j] = 1e4;
            }
        }
        queue<vector<int>>q; q.push(entrance); step[entrance[0]][entrance[1]] = 0;
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int x = top[0], y = top[1];
            int dx[] = {0, 1, 0, -1},  dy[] = {1, 0, -1, 0};
            for(int k = 0; k < 4; k++){
                int kx = x + dx[k], ky = y + dy[k];
                if(kx > -1 && kx < maze.size() &&
                   ky > -1 && ky < maze[0].size() &&
                   maze[kx][ky] == '.' && step[kx][ky] > step[x][y] + 1){
                    //cout << kx << ' ' << ky << endl;
                    if(kx == 0 || kx == maze.size() - 1 || ky == 0 || ky == maze[0].size() - 1) return step[x][y] + 1;
                    step[kx][ky] = step[x][y] + 1;
                    q.push(vector<int>{kx, ky});
                }
            }
        }
        return -1;
    }
};