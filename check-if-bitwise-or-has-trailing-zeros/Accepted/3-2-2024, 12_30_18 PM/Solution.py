// https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros

class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        l = [x % 2 == 0 for x in nums]
        return l.count(1) > 1