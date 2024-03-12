// https://leetcode.com/problems/valid-anagram

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sd, td = {}, {}
        for i in s:
            sd[i] = sd.setdefault(i, 0) + 1
        for i in t:
            td[i] = td.setdefault(i, 0) + 1
        return sd == td