// https://leetcode.com/problems/new-21-game

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k + maxPts) return 1;
        vector<vector<double> > dp;
        dp.resize(n + 1, vector<double>(n + maxPts, .0)); dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < k; j++){
                for(int a = 1; a <= maxPts; a++){
                    dp[i][j + a] += dp[i - 1][j] * double(1.0/maxPts);
                }
            }
        }
        double ans = .0;
        for(int i = 1; i <= k; i++){
            for(int j = k; j <= n; j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
};  