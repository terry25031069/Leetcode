// https://leetcode.com/problems/number-of-even-and-odd-bits

class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        s = "{0:b}".format(n)
        s = s[::-1]
     
        ans = [0, 0]
        for i in range(len(s)):
            if s[i] == '1': ans[i % 2] += 1
        return ans
                
        