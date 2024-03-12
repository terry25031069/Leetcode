// https://leetcode.com/problems/minimum-common-value

class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2 = set(nums1), set(nums2)
        for i in sorted(list(s1)):
            if i in s2: 
                return i
        return -1