// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = 1e9;
        for(auto v: roads){
            ans = min(ans, v[2]);
        }
        return ans;
    }
};