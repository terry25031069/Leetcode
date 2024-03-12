// https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ma = 0, ans = 0;
        for(auto v: dimensions){
            if(ma <= v[0] * v[0] + v[1] * v[1] && ans <= v[0] * v[1]){
                ans = v[0] * v[1], ma = v[0] * v[0] + v[1] * v[1];
            }
        }
        return ans;
    }
};