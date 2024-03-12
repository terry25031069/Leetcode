// https://leetcode.com/problems/climbing-stairs

class Solution:
    def climbStairs(self, n: int) -> int:
        t, tt = 1, 2
        for i in range(n-1):
            t, tt = tt, tt + t
        return t