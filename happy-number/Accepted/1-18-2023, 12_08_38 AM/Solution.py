// https://leetcode.com/problems/happy-number

class Solution:
    def isHappy(self, n: int) -> bool:
        d = {}
        while n not in d and n != 1:
            d[n] = 1
            tmp, ans = n, 0
            while tmp > 0:
                ans += (tmp % 10) ** 2
                tmp //= 10
            n = ans
        return n == 1