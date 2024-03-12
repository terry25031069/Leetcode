// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

typedef long long ll;
#define MOD 1000000007

class Solution {
public:
    ll dp[40][1001] = {};
    int dfs(int n, int k, int target){
        if(target < n || target > k * n) return 0;
        if(target == n || target == k * n) return 1;
        if(dp[n][target]) return dp[n][target];
        for(int i = 1; i <= k; i++){
            dp[n][target] += dfs(n-1, k, target - i);
            dp[n][target] %= MOD;
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        for(int i = 1; i < k + 1; i++) dp[1][i] = 1;
        return dfs(n, k, target);
    }
};