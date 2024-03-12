// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    struct node{
        int x, y, step;
        node(int xx, int yy, int s):x(xx), y(yy), step(s){}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<node> q;
        if(grid[0][0]) return -1;
        q.push({0, 0, 1}); 
        grid[0][0] = 1;
        int dx[] = {-1,-1,-1,0,1,1,1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            node tmp = q.front(); q.pop();
            for(int k = 0; k < 8; k++){
                int nx = tmp.x + dx[k], ny = tmp.y + dy[k];
                if(nx > -1 && nx < grid.size() && ny > -1 && ny < grid[0].size() 
                     && !grid[nx][ny]){
                    cout << nx << ' ' << ny << endl;
                    if(nx == grid.size() - 1 && ny == grid[0].size() - 1) return tmp.step + 1;
                    q.push({nx, ny, tmp.step + 1});
                    grid[nx][ny] = 1;
                }
            }
        }
        return -1;
    }
};