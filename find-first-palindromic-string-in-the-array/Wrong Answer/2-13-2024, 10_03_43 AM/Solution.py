// https://leetcode.com/problems/find-first-palindromic-string-in-the-array

class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for s in words:
            if s[::-1] == s:
                return s