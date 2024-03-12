// https://leetcode.com/problems/maximum-score-after-splitting-a-string

class Solution:
    def maxScore(self, s: str) -> int:
        ans = 0
        for i in range(1, len(s)):
            l, r = s[:i], s[i:]
            ans = max(ans, l.count('0') + r.count('1'))
        return ans