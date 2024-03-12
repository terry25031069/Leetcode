// https://leetcode.com/problems/number-of-changing-keys

class Solution:
    def countKeyChanges(self, s: str) -> int:
        s = s.lower()
        ans, cur = -1, ''
        for ch in s:
            if cur != ch: 
                ans += 1
                cur = ch
        return ans
