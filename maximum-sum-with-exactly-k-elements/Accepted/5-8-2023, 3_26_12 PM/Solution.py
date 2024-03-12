// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements

class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        t = max(nums) 
        ans = 0
        for i in range(k): 
            ans += t
            t += 1
        return ans