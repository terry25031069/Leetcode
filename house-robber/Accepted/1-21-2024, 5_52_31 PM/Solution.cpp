// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n, 0), dp(n, 0);
        for(int i = 0; i < n; i++){
            tmp[i] = nums[i];
            if(i > 1) tmp[i] += dp[i - 2];
            if(i > 0) dp[i] = max(tmp[i], tmp[i-1]);
            else dp[i] = tmp[i];
        }
        return dp.back();
    }
};