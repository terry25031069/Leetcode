// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            int row = m / matrix[0].size(), col = m % matrix[0].size();
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
};