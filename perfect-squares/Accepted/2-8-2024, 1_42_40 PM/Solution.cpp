// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        int dp[10001] = {0, };
        for(int i = 1; i < n + 1; i++) dp[i] = n + 1;
        for(int i = 1; i < 101; i++){
            for(int j = 0; i*i+j < n + 1; j++){
                if(dp[j + i * i] > dp[j] + 1){
                    dp[j + i * i] = dp[j] + 1;
                }
            }
        }
        return dp[n];
    }
};