// https://leetcode.com/problems/merge-strings-alternately

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        t = max(len(word1), len(word2))
        if t > len(word1): word1 += ' ' * (t - len(word1))
        if t > len(word2): word2 += ' ' * (t - len(word2))
        ans = ''
        for i in range(t):
            ans += word1[i] + word2[i]
        return ans.replace(' ', '')