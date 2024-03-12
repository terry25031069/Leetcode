// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        p = [i for i in nums if i > 0]
        n = [i for i in nums if i < 0]
        l = [[p[i], n[i]] for i in range(len(p))]
        l = [ele for ll in l for ele in ll]
        return l