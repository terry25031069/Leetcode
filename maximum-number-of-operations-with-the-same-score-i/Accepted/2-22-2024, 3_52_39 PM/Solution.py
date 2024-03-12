// https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i

class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        score = nums[0] + nums[1]
        cnt, i = 0, 0
        while i < len(nums) - 1:
            print(i)
            if score == nums[i] + nums[i+1]: 
                cnt += 1
                i += 2
            else: break
        return cnt