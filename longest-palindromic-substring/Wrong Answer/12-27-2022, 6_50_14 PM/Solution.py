// https://leetcode.com/problems/longest-palindromic-substring

class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans, maxlen = "" , 0
        if len(s) == 1: return s
        if len(s) == 2:
            if s[0] == s[1]: return s
            return s[0]
        for i in range(len(s)):
            start, end = i, i
            while 1:
                if s[start: end + 1] == s[end:start -1 :-1]: 
                    if maxlen < end - start + 1:
                        maxlen = end - start + 1
                        ans = s[start: end + 1]
                    if start < 0 or end == len(s): break
                    else: 
                        start -= 1
                        end += 1
                else: break
        for i in range(len(s)):
            start, end = i, i + 1
            while 1:
                if s[start: end + 1] == s[end:start - 1:-1]: 
                    if maxlen < end - start + 1:
                        maxlen = end - start + 1
                        ans = s[start: end + 1]
                    if start < 0 or end == len(s): break
                    else: 
                        start -= 1
                        end += 1
                else: break
        return ans
            
                    