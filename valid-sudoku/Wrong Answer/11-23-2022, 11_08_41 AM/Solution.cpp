// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            int checkrow[10] = {}, checkcol[10] = {}, checkgrid[10] = {};
            int basrow = (i / 3) * 3 + 1, bascol = (i % 3) * 3 + 1;
            for(int j = 0; j < 9; j++){  
                int dx = j / 3 - 1, dy = j % 3 - 1;
                if(board[i][j] != '.')checkrow[board[i][j] - '0']++;
                if(board[j][i] != '.')checkcol[board[j][i] - '0']++;
                if(board[basrow + dx][bascol + dy] != '.'){
                    //cout << basrow + dx << ' ' << bascol + dy << endl;
                    checkgrid[board[basrow + dx][bascol + dy] - '0']++;

                }
            }
            for(int j = 1; j < 10; j++){
                if(checkrow[j] > 1 || checkcol[j] > 1 || checkgrid[i] > 1) return false;
            }
        }
        return true;
    }
};