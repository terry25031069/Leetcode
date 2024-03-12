// https://leetcode.com/problems/integer-break

class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4: return n - 1
        d, r = n // 3, n % 3
        if r == 0:
            return 3 ** d
        if r == 1:
            return 3 ** (d - 1) * 4
        if r == 2: 
            return 3 ** d * 2
