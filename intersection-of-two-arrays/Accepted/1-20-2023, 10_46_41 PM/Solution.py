// https://leetcode.com/problems/intersection-of-two-arrays

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d1, d2 = {}, {}
        ans = []
        for i in nums1: 
            d1[i] = 1
        for i in nums2: 
            d2[i] = 1
        for key, value in d1.items():
            if key in d2:
                ans.append(key)
        return ans
