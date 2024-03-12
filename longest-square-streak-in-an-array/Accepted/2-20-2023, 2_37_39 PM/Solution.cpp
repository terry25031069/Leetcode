// https://leetcode.com/problems/longest-square-streak-in-an-array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<long long, int> m, dp;
        int ans = -1;
        for(int i: nums) m[i]++, dp[i] = 1;
        for(auto [k, v]: m){
            if(!m[k]) continue;
            if(m[(long long)k * k]){
                dp[(long long)k * k] = dp[k] + 1;
                ans = max(ans, dp[k] + 1);
            }
        }
        return ans;
    }
};