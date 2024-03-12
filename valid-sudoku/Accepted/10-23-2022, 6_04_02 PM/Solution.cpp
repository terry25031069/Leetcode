// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for(int i = 0; i < 9; i++){
        //     for(int j = 0; j < 9; j++){
        //         cout << board[i][j] << " \n"[j == 8];
        //     }
        // }
        for(int i = 0; i < 9; i++){
            int checkrow[10] = {}, checkcol[10] = {};
            for(int j = 0; j < 9; j++){  
                if(board[i][j] != '.')checkrow[board[i][j] - '0']++;
                if(board[j][i] != '.')checkcol[board[j][i] - '0']++;
            }
            for(int j = 1; j < 10; j++){
                if(checkrow[j] > 1 || checkcol[j] > 1) return false;
            }
        }
        for(int cnt = 0; cnt < 9; cnt++){
            int basrow = (cnt / 3) * 3 + 1, bascol = (cnt % 3) * 3 + 1;
            int check[10] = {};
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if(board[basrow + i][bascol + j] != '.')check[board[basrow + i][bascol + j] - '0']++;
                }
            }
            for(int i = 1; i < 10; i++){
                if(check[i] > 1) return false;
            }
        }
        return true;
    }
};