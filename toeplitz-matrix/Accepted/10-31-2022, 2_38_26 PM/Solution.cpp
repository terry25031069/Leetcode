// https://leetcode.com/problems/toeplitz-matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int dig[1000] = {};
        for(int i = 0; i < 1000; i++) dig[i] = -1;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                if(dig[i - j + 100] == -1) dig[i - j + 100] = matrix[i][j];
                else{
                    if(dig[i - j + 100] - matrix[i][j]) return false;
                }
            }
        }
        return true;
    }
};