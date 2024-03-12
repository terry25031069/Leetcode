// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = 1e9;
        for(int i = 0; i < triangle.size(); i++){
            for(int j = 0; j <= i; j++){
                if(i || j){
                    if(i == j) triangle[i][j] += triangle[i-1][j-1];
                    else if(j < 1) triangle[i][j] += triangle[i-1][j];
                    else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
                if(i == triangle.size() - 1){
                    ans = min(ans, triangle[i][j]);
                }
            }
        }
        return ans;
    }
};