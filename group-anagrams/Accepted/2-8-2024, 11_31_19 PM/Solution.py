// https://leetcode.com/problems/group-anagrams

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            tmp = "".join(sorted(s))
            d[tmp] = d.setdefault(tmp, [])
            d[tmp].append(s)
        return d.values()