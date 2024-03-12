// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    using pii = pair<int, int>;
    bool b;
    vector<pii> point;
    void dfs(int i, int j, vector<vector<char>>& board){
        board[i][j] = 'X';
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for(int k = 0; k < 4; k++){
            int tx = i + dx[k], ty = j + dy[k];
            if(tx > -1 && tx < board.size() && ty > -1 && ty < board[0].size() 
            && board[tx][ty] == 'O'){
                point.push_back({tx, ty});
                dfs(tx, ty, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    point.clear(), point.push_back({i, j});
                    dfs(i, j, board);
                    bool b = (!(i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() -1));
                    for(auto v: point){
                        int x = v.first, y = v.second;
                        b &= (!(x == 0 || y == 0 || x == board.size() - 1 || y == board[0].size() -1));
                    }
                    for(auto v: point){
                        board[v.first][v.second] = (b == 0 ? 'O' : 'X');
                    }
                }
            }
        }
    }
};