// https://leetcode.com/problems/intersection-of-two-arrays

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2): 
            nums1, nums2 = nums2, nums1
        ans = []
        for i in nums1:
            if i in nums2:
                if i not in ans:
                    ans.append(i)
        return ans
