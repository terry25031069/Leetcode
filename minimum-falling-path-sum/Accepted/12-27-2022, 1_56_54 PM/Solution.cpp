// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size() == 1) return matrix[0][0];
        int ans = 1e9;
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                if(j == 0) matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                else if(j == matrix.size() - 1) matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                else matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i-1][j], matrix[i-1][j + 1]));
                if(i == matrix.size() - 1) ans = min(ans, matrix[i][j]);
                //cout << matrix[i][j] << ' ';
            }
            //cout << endl;
        }
        return ans;
    }
};