// https://leetcode.com/problems/minimum-string-length-after-removing-substrings

class Solution:
    def minLength(self, s: str) -> int:
        while "AB" in s or "CD" in s:
            while "AB" in s: s = s.replace("AB", "")
            while "CD" in s: s = s.replace("CD", "")
        return len(s)
