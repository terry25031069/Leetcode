// https://leetcode.com/problems/valid-anagram

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sd, td = {}, {}
        for i in s:
            if i not in sd: sd[i] = 0 
            sd[i] += 1
        for i in t:
            if i not in td: td[i] = 0
            td[i] += 1
        return sd == td