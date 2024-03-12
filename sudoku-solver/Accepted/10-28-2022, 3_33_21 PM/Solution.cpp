// https://leetcode.com/problems/sudoku-solver

class Solution {

public:
    int flag = 0;
    void print(vector<vector<char>> board){
        for(int i = 0 ; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j] << " \n"[j == 8];
            }
        }
        cout << endl;
    }
    
    void dfs(vector<vector<char>> &board, int x, int y){
        if(x == 9 && y == 0){
            flag = 1;
            return;
        }
        if(x == 8 && y == 8){
            print(board);
        }
        if(board[x][y] == '.'){
            int ar[10] = {}; memset(ar, 1, sizeof(ar));
            int gx = (x / 3) * 3 + 1, gy = (y / 3) * 3 + 1;
            for(int i = 0; i < 9; i++){
                int dx = (i / 3) - 1, dy = (i % 3) - 1;
                if(board[x][i] != '.')ar[board[x][i] - '0'] = 0;
                if(board[i][y] != '.')ar[board[i][y] - '0'] = 0;
                if(board[gx + dx][gy + dy] != '.')ar[board[gx + dx][gy + dy] - '0'] = 0;
            } 
            for(int i = 1; i < 10; i++){
                if(ar[i]){
                    board[x][y] = i + '0';
                    y == 8? dfs(board, x + 1, 0): dfs(board, x, y + 1);
                    if(flag) return;
                    board[x][y] = '.';
                }
            }
        }else{
            y == 8? dfs(board, x + 1, 0): dfs(board, x, y + 1);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        flag = 0;
        dfs(board, 0, 0);
    }
};