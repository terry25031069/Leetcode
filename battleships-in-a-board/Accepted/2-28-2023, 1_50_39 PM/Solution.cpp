// https://leetcode.com/problems/battleships-in-a-board

class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    void dfs(int x, int y, vector<vector<char>>& board){
        board[x][y] = '.';
        for(int k = 0; k < 4; k++){
            int tx = x + dx[k], ty = y + dy[k];
            if(tx > -1 && tx < board.size() && ty > -1 && ty < board[0].size() && board[tx][ty] == 'X'){
                dfs(tx, ty, board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'X') dfs(i, j, board), ans++;
            }
        }
        return ans;
    }
};