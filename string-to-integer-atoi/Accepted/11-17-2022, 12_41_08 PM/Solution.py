// https://leetcode.com/problems/string-to-integer-atoi

class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if len(s) == 0: return 0
        location = len(s)
        for i in range((s[0] == '-' or s[0] == '+'), len(s)):
            if s[i].isdigit() == 0:
                location = i
                break
        s = s[:location]
        if len(s) == 0: return 0
        print(s)
        if s[0].isdigit(): s = '+' + s
        if s[1:].isdigit() == 0: return 0
        ans = int(s)
        if ans > 2 ** 31 - 1: return 2 ** 31 - 1
        elif ans < -2 ** 31: return -2 ** 31
        else: return ans