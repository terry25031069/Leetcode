// https://leetcode.com/problems/most-common-word

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.split()
        d = {}
        for i in paragraph:
            tmp = "".join([c.lower() for c in i if c.isalpha()])
            if tmp not in banned:
                d[tmp] = d.setdefault(tmp, 0) + 1
        ma, ans = 0, ""
        for k, v in d.items():
            if v > ma:
                ma = v
                ans = k
        return ans 

            