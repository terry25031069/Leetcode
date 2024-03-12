// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int dp[1001][1001] = {};
    int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};