// https://leetcode.com/problems/isomorphic-strings

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        def tra(s):
            d = {}
            ans = []
            for ch in s:
                d[ch] = d.setdefault(ch, len(d))
                ans.append(d[ch])
            return ans
        return tra(s) == tra(t)
        