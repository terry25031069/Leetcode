// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001] = {};
        fill_n(dp, 10001, 1e9); dp[0] = 0;
        for(int c: coins){
            for(int i = c; i <= amount; i++){
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
        if(dp[amount] == 1e9) return -1;
        return dp[amount];
    }
};