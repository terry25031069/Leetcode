// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        using pii = pair<int, int>;
        vector<vector<int>> dis(n, vector<int>(n, 1e6));
        queue<pii> q; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while(!q.empty()){
            pii t = q.front(); q.pop();
            int x = t.first, y = t.second;
            for(int k = 0; k < 4; k++){
                if(x + dx[k] > -1 && x + dx[k] < n && 
                   y + dy[k] > -1 && y + dy[k] < n && 
                   dis[x + dx[k]][y + dy[k]] > dis[x][y] + 1){
                    dis[x + dx[k]][y + dy[k]] = dis[x][y] + 1;
                    q.push({x + dx[k], y + dy[k]});
                }
            }
        }
        vector<int> tmp;
        for(auto v: dis) tmp.push_back(*max_element(v.begin(), v.end()));
        return *max_element(tmp.begin(), tmp.end());
    }
};