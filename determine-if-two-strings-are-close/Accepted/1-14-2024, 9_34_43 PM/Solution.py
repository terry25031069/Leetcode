// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        d1, d2 = {}, {}
        for ch in word1: d1[ch] = d1.setdefault(ch, 0) + 1
        for ch in word2: d2[ch] = d2.setdefault(ch, 0) + 1
        l1, l2 = d1.values(), d2.values()
        return sorted(l1) == sorted(l2) and set(d1.keys()) == set(d2.keys())