// https://leetcode.com/problems/split-strings-by-separator

class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for s in words:
            ans += [i for i in s.split(separator) if len(i)]
        return ans