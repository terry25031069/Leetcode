// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [1e9] * (days[-1] + 1)
        dp[0] = 0
        for i in range(days[-1] + 1):
            if i in days:
                if i > 0: dp[i] = min(dp[i-1] + costs[0], dp[i])
                if i > 6: dp[i] = min(dp[i-7] + costs[1], dp[i])
                if i > 29: dp[i] = min(dp[i-30] + costs[2], dp[i])
            else:
                if i > 0: dp[i] = min(dp[i], dp[i-1])
        return dp[days[-1]]