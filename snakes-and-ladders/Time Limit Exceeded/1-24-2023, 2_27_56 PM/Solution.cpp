// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:
    pair<int, int> trans(int t, int n){
        int tmp = n * n - t;
        return {tmp/n, n - 1 - tmp % n};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q; q.push(1);
        queue<int> step; step.push(0);
        int n = board.size();
        while(!q.empty()){
            int t = q.front(); q.pop();
            int curstep = step.front(); step.pop();
            //cout << t << ' ' << curstep << endl;
            for(int i = 1; i <= 6; i++){
                if(t + i <= n * n){
                    auto [x, y] = trans(t + i, n);
                    if(board[x][y] != -1){
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