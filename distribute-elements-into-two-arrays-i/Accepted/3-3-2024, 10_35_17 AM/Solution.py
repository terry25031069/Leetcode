// https://leetcode.com/problems/distribute-elements-into-two-arrays-i

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        l1, l2 = [], []
        for i in range(len(nums)):
            if i == 0: l1.append(nums[i])
            elif i == 1: l2.append(nums[i])
            else:
                l1.append(nums[i]) if l1[-1] > l2[-1] else l2.append(nums[i])
        return l1 + l2