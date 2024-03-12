// https://leetcode.com/problems/valid-parentheses

class Solution:
    def isValid(self, s: str) -> bool:
        length = len(s)
        while len(s):
            flag = 0
            i = 0
            while i < length - 1:
                if (s[i] == '(' and s[i + 1] == ')') or (s[i] == '[' and s[i + 1] == ']') or (s[i] == '{' and s[i + 1] == '}'):
                    s = s[:i] + s[i + 2:]
                    flag = 1
                    i -= 2
                    length -= 2
                    break
                i += 1
            if flag == 0:
                break
                
        return s == ''