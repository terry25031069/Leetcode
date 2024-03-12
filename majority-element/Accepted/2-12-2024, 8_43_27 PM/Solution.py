// https://leetcode.com/problems/majority-element

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans, cnt = nums[0], 0
        for i in nums:
            if ans == i: 
                cnt += 1
            else:
                cnt -= 1
                if cnt < 0: 
                    ans = i
                    cnt = 1
        return ans
    