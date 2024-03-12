// https://leetcode.com/problems/sort-vowels-in-a-string

class Solution:
    def sortVowels(self, s: str) -> str:
        v = []
        for i in s:
            if i.upper() in "AEIOU":
                v.append(i)
        v = sorted(v)
        ans = []
        for i in s:
            if i.upper() in "AEIOU":
                ans.append(v[0])
                del v[0]
            else:
                ans.append(i)
        return "".join(ans)
        