// https://leetcode.com/problems/increment-submatrices-by-one

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n));
        for(auto q: queries){
            int x0 = q[0], y0 = q[1], x1 = q[2], y1 = q[3];
            for(int i = x0; i <= x1; i++){
                for(int j = y0; j <= y1; j++){
                    ans[i][j] ++;
                }
            }
        }
        return ans;
    }
};