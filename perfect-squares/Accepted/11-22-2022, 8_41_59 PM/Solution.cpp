// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        int dp[10001] = {0, };
        for(int i = 1; i < 10001; i++) dp[i] = 10001;
        for(int i = 1; i < 101; i++){
            for(int j = 0; i*i+j < 10001; j++){
                if(dp[j + i * i] > dp[j] + 1){
                    dp[j + i * i] = dp[j] + 1;
                }
            }
        }
        return dp[n];
    }
};