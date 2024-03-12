// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        d = {}
        for i in nums: d[i] = d.get(i, 0) + 1
        ma = max(d.values())
        return ma * list(d.values()).count(ma)