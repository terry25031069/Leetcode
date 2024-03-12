// https://leetcode.com/problems/group-anagrams

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        ans = []
        for i in strs:
            s = str(sorted(i))
            # d[s] = d.setdefault(s, []).append(i)
            if s not in d:
                d[s] = []
            d[s].append(i)
        for key, val in d.items():
            ans.append(val)
        return ans
