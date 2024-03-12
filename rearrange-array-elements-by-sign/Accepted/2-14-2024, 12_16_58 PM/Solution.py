// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        p = [i for i in nums if i > 0]
        n = [i for i in nums if i < 0]
        l = [[p[i], n[i]] for i in range(len(p))]
        return [j for i in l for j in i]