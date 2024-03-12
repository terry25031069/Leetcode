// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row[matrix.size()], col[matrix[0].size()];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(!matrix[i][j]){
                    row[i] = col[j] = 1;
                }
            }
        }
        // for(auto i: row) cout << i << ' '; cout << endl;
        // for(auto i: col) cout << i << ' '; cout << endl;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};