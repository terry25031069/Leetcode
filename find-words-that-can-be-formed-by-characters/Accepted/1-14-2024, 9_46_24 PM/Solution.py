// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def chf(s: string):
            d = {}
            for ch in s:
                d[ch] = d.setdefault(ch, 0) + 1
            return d
        ans = 0
        tmp = chf(chars)
        for s in words:
            tmp0 = chf(s)
            flag = 0
            for k, v in tmp0.items():
                if k not in tmp or v > tmp[k]: flag = 1
            if not flag: ans += len(s)
        return ans