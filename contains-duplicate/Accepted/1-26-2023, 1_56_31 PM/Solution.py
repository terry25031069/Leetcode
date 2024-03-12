// https://leetcode.com/problems/contains-duplicate

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        d = {}
        for i in nums: 
            d[i] = d.setdefault(i, 0) + 1
            if d[i] == 2: return 1
        return 0