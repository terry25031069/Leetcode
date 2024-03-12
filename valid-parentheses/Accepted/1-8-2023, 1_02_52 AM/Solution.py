// https://leetcode.com/problems/valid-parentheses

class Solution:
    def isValid(self, s: str) -> bool:
        while len(s):
            flag = 0
            for i in range(len(s) - 1):
                if (s[i] == '(' and s[i + 1] == ')') or (s[i] == '[' and s[i + 1] == ']') or (s[i] == '{' and s[i + 1] == '}'):
                    s = s[:i] + s[i + 2:]
                    flag = 1
                    break
            if flag == 0:
                break
                
        return s == ''