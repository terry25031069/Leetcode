// https://leetcode.com/problems/game-of-life

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> nextBoard = board;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int cnt = 0;
                for(int dx = -1; dx < 2; dx++){
                    for(int dy = -1; dy < 2; dy++){
                        if(dx || dy){
                            if(i + dx > -1 && i + dx < board.size() && j + dy > -1 && j + dy < board[0].size() && board[i+dx][j+dy]) cnt++;
                        }
                    }
                }
                if(board[i][j]){
                    if(cnt < 2 || cnt > 3) nextBoard[i][j] = 0;
                    else nextBoard[i][j] = 1;
                }else{
                    if(cnt == 3) nextBoard[i][j] = 1;
                    else nextBoard[i][j] = 0;
                }
            }
        }
        board = nextBoard;
    }
};