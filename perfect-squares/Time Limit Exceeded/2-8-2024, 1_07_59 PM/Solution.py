// https://leetcode.com/problems/perfect-squares

class Solution:
    def numSquares(self, n: int) -> int:
        bars = [x * x for x in range(1, 101)]
        dp = [10001] * 10001
        dp[0] = 0
        for bar in bars:
            for j in range(0, 10000 - bar):
                dp[j + bar] = min(dp[j + bar], dp[j] + 1)
        return dp[n]