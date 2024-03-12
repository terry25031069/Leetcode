// https://leetcode.com/problems/word-pattern

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        d0 = {}
        d1 = {}
        for i in range(len(s)):
            if pattern[i] not in d0 and s[i] not in d1:
                d0[pattern[i]] = s[i]
                d1[s[i]] = pattern[i]
            else:
                if pattern[i] not in d0 or d0[pattern[i]] != s[i]: return False
                if s[i] not in d1 or d1[s[i]] != pattern[i]: return False
        return True