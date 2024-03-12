// https://leetcode.com/problems/sort-characters-by-frequency

class Solution:
    def frequencySort(self, s: str) -> str:
        d = {}
        for ch in s: d[ch] = d.setdefault(ch, 0) + 1
        s = sorted(s, key = lambda x: d[x], reverse = True)
        return s
        