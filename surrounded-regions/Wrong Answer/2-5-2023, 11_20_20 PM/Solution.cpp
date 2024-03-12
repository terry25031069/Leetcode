// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    map<int, int> m;
    vector<vector<int>> point;
    set<vector<int>> s;
    bool dfs(int i, int j, vector<vector<char>>& board){
        bool b = 1;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        for(int k = 0; k < 4; k++){
            int tx = i + dx[k], ty = j + dy[k];
            if(tx > -1 && tx < board.size() && ty > -1 && ty < board[0].size() 
            && board[tx][ty] == 'O' && s.find({tx, ty}) == s.end()){
                b &= (!(tx == 0 || ty == 0 || tx == board.size() - 1 || ty == board[0].size() - 1));
                point.push_back({tx, ty});
                s.insert({tx, ty});
                dfs(tx, ty, board);
            }
        }
        return b;
    }

    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    s.clear(); point.clear();
                    bool b = dfs(i, j, board);
                    for(auto v: point){
                        board[v[0]][v[1]] = (b == 0 ? 'O' : 'X');
                    }
                }
            }
        }
    }
};