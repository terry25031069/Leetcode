// https://leetcode.com/problems/find-the-array-concatenation-value

class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        ans = 0
        for i in range(0, len(nums) // 2):
            tmp = int(str(nums[i]) + str(nums[-1-i]))
            ans += tmp
        if len(nums) % 2 != 0: ans += nums[len(nums) // 2]
        return ans