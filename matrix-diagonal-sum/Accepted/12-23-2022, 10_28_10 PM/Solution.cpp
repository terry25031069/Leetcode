// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            if(mat.size() - 1 - i - i)ans += mat[i][i] + mat[mat.size() - 1 - i][i];
            else ans += mat[i][i];
        }
        return ans;
    }
};