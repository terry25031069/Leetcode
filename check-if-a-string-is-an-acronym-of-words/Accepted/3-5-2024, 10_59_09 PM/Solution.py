// https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words

class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        return s == "".join([s[0] for s in words])