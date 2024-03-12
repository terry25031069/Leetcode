// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:
    pair<int, int> trans(int t, int n){
        int tmp = n * n - t;
        int x = tmp / n, y = 0;
        if((n + tmp / n) % 2 == 1) y = n - 1 - tmp % n;
        else y = tmp % n;
        return {x, y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q; q.push(1);
        queue<int> step; step.push(0);
        int n = board.size();
        vector<bool> visit(n * n + 1, 0); visit[1] = 1;
        while(!q.empty()){
            int t = q.front(); q.pop();
            int curstep = step.front(); step.pop();
            for(int i = 1; i <= 6; i++){
                if(t + i <= n * n && visit[t + i] == 0){
                    auto [x, y] = trans(t + i, n);
                    visit[t + i] = 1;
                    if(board[x][y] != -1 && !visit[board[x][y]]){
                        if(board[x][y] == n * n) return curstep + 1;
                        q.push(board[x][y]);
                    }else{
                        if(t + i == n * n) return curstep + 1;
                        q.push(t + i);
                    }
                    step.push(curstep + 1);
                }
            }
        }
        return -1;
    }
};