// https://leetcode.com/problems/valid-number

class Solution:
    def isNumber(self, s: str) -> bool:
        if s[0] == '+' or s[0] == '-': s = s[1:]
        s = s.lower()
        s = s.replace("e-", 'e').replace('e+', 'e')
        for i in s:
            if not (i.isdigit() or i == 'e' or i == '.'): return False
        if s.count("e") > 1 or s.count(".") > 1: return False
        s = s.split("e")
        if len(s) == 1:
            return s[0].replace(".", "").isdigit()
        else:
            if len(s) == 2:
                return s[0].replace(".", "").isdigit() and s[1].isdigit()
            return False

        