// https://leetcode.com/problems/relative-ranks

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        l = sorted(score, reverse = True)
        ans = [str(l.index(x) + 1) for x in score]
        for i in range(len(score)):
            if ans[i] == '1': ans[i] = 'Gold Medal'
            if ans[i] == '2': ans[i] = 'Silver Medal'
            if ans[i] == '3': ans[i] = 'Bronze Medal'
        return ans
        