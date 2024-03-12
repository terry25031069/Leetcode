// https://leetcode.com/problems/partition-array-for-maximum-sum

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0); dp[0] = arr[0];
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= k; j++){
                int curMax = *max_element(arr.begin() + i - j + 1, arr.begin() + i + 1);
                if(i - j == -1){
                    dp[i] = max(dp[i], j * curMax);
                    break;
                }
                dp[i] = max(dp[i], dp[i-j] + j * curMax);
            }
            //cout << dp[i] << ' ';
        }
        return dp.back();
    }
};