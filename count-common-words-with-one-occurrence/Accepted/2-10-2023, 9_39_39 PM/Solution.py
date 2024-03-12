// https://leetcode.com/problems/count-common-words-with-one-occurrence

class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        d = {}
        ans = 0
        for s in words1: d[s] = d.setdefault(s, 0) + 1
        for s in words2: d[s] = d.setdefault(s, 0) + 1001
        for k, v in d.items(): 
            if v == 1002:
                ans += 1
        return ans
