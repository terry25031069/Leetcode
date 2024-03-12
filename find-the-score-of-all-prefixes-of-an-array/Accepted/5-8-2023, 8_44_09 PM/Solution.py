// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array

class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        ans = []
        ma = 0
        for i in range(len(nums)):
            ma = max(ma, nums[i])
            ans.append(nums[i] + ma)
            if i > 0: ans[i] += ans[i-1]
        return ans