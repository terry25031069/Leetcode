// https://leetcode.com/problems/decode-ways

d = {}

def chk(s: str):
    return 1 <= int(s) <= 26

class Solution:
    def numDecodings(self, s: str) -> int:
        for i in range(1, 27): 
            if i < 11 or i == 20: d[str(i)] = 1
            else: d[str(i)] = 2
        def r(s):
            ans = 0
            if s[0] == '0': 
                return 0
            if s in d: 
                return d[s]
            if len(s) > 1 and chk(s[:1]):     
                ans += d.setdefault(s[1:], r(s[1:]))
            if len(s) > 2 and chk(s[:2]): 
                ans += d.setdefault(s[2:], r(s[2:]))
            d[s] = ans
            return ans
        return r(s)