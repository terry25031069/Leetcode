// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [1e9] * (days[-1] + 31)
        dp[0] = 0
        for i in range(1, days[-1] + 31):
            dp[i] = min(dp[i-1] + costs[0], dp[i])
            if i > 6: dp[i] = min(dp[i-7] + costs[1], dp[i])
            if i > 29: dp[i] = min(dp[i-30] + costs[2], dp[i])
            if i not in days: dp[i] = min(dp[i], dp[i-1])
        return min(dp[days[-1]: days[-1] + 30])