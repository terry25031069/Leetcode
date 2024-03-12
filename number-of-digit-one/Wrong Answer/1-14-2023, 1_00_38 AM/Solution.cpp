// https://leetcode.com/problems/number-of-digit-one

class Solution {
public:
    int countDigitOne(int n) {
        long long dp[10][10] = {1, 0, 1},  bas = 1; 
        dp[1][1] = 1;
        for(int i = 1; i < 9; i++) dp[i][0] = dp[i-1][0] * 10;
        for(int j = 0; j < 9; j++){
            for(int i = 1; i < 10; i++){
                if(j > 1 && i == 1) dp[j][i] = dp[j-1][i] / (j-1) * j * 10;
                else if(i != 1 || (j != 0 && j != 1)){
                    dp[j][i] = dp[j][i-1] + dp[j][1] + (i == 2) * dp[j][0];
                }
            }
        }
        int ans = 0, t = n, ba = 0;
        while(t){
            if(t % 10)ans += dp[ba][t % 10];
            t /= 10, ba++;
        }
        ba = 1e9;
        while(ba){
            if(n / ba % 10 == 1){
                n %= ba, ans += (n + 1);
            }
            ba /= 10;
        }
        return ans;
    }
};