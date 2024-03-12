// https://leetcode.com/problems/string-to-integer-atoi

class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        location = len(s)
        for i in range(len(s)):
            if s[0] == '-': continue
            if s[i].isdigit() == 0:
                location = i
                break
        s = s[:location]
        if len(s) == 0: s = '0'
        if s[0] == '+': s = s[1:]
        try:
            ans = int(s)
        except:
            return 0
        if ans > 2 ** 31 - 1: return 2 ** 31 - 1
        elif ans < -2 ** 31: return -2 ** 31
        else: return ans
