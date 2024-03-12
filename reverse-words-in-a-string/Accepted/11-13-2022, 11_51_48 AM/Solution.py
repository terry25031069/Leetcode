// https://leetcode.com/problems/reverse-words-in-a-string

class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        while s.find("  ") != -1: s = s.replace("  ", " ")
        s = " ".join(s.split()[::-1])
        return s