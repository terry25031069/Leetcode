// https://leetcode.com/problems/count-the-digits-that-divide-a-number

class Solution:
    def countDigits(self, num: int) -> int:
        s = str(num)
        ans = 0
        for i in s:
            t = int(i)
            if num % t == 0:
                ans += 1
        return ans
        