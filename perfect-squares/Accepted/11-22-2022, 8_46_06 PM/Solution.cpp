// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        int dp[10001] = {0, };
        for(int i = 1; i < n + 1; i++) dp[i] = 10001;
        for(int i = 1; i < sqrt(n + 1); i++){
            for(int j = 0; i*i+j < n + 1; j++){
                if(dp[j + i * i] > dp[j] + 1){
                    dp[j + i * i] = dp[j] + 1;
                }
            }
        }
        return dp[n];
    }
};