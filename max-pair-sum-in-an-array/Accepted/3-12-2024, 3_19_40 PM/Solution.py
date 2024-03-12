// https://leetcode.com/problems/max-pair-sum-in-an-array

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        m = {}
        for n in nums:
            max_digit = max(str(n))
            m[max_digit] = m.setdefault(max_digit, [])
            m[max_digit].append(n)
        ma = -1
        for key, val in m.items():
            if len(val) < 2: continue
            val = sorted(val, reverse=True)
            ma = max(ma, sum(val[:2]))
        return ma
        
        
        
