// https://leetcode.com/problems/merge-strings-alternately

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        t = min(len(word1), len(word2))
        ans = "".join([word1[i] + word2[i] for i in range(t)])
        return ans + word1[t:] + word2[t:]