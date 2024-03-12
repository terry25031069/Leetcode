// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j] << " \n"[j == 8]; 
            }
        }
        for(int i = 0; i < 9; i++){
            int checkrow[10] = {}, checkcol[10] = {}, checkgrid[10] = {};
            int basrow = (i / 3) * 3 + 1, bascol = (i % 3) * 3 + 1;
            for(int j = 0; j < 9; j++){  
                int dx = j / 3 - 1, dy = j % 3 - 1;
                if(board[i][j] != '.')checkrow[board[i][j] - '0']++;
                if(board[j][i] != '.')checkcol[board[j][i] - '0']++;
                if(board[basrow + dx][bascol + dy] != '.'){
                    checkgrid[board[basrow + dx][bascol + dy] - '0']++;
                }
            }
            for(int j = 1; j < 10; j++){
                cout << checkgrid[i] << " \n"[j == 9];
                if(checkrow[j] > 1 || checkcol[j] > 1 || checkgrid[j] > 1) return false;
            }
            cout << endl;
        }
        return true;
    }
};


//  for(int cnt = 0; cnt < 9; cnt++){
//     int basrow = (cnt / 3) * 3 + 1, bascol = (cnt % 3) * 3 + 1;
//     int check[10] = {};
//     for(int i = -1; i < 2; i++){
//         for(int j = -1; j < 2; j++){
//             if(board[basrow + i][bascol + j] != '.')check[board[basrow + i][bascol + j] - '0']++;
//         }
//     }
//     for(int i = 1; i < 10; i++){
//         if(check[i] > 1) return false;
//     }
// }