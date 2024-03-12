// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int visit[101][101] = {};
        entrance.push_back(0);
        queue<vector<int>>q; q.push(entrance);
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int x = top[0], y = top[1], step = top[2];
            visit[x][y] = 1;
            int dx[] = {0, 1, 0, -1},  dy[] = {1, 0, -1, 0};
            for(int k = 0; k < 4; k++){
                int kx = x + dx[k], ky = y + dy[k];
                if(kx > -1 && kx < maze.size() && ky > -1 && ky < maze[0].size() && maze[kx][ky] == '.' && visit[kx][ky] == 0){
                    //cout << kx << ' ' << ky << endl;
                    if(kx == 0 || kx == maze.size() - 1 || ky == 0 || ky == maze[0].size() - 1) return step + 1;
                    q.push(vector<int>{kx, ky, step + 1});
                }
            }
        }
        return -1;
    }
};