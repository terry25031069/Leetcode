// https://leetcode.com/problems/minimize-maximum-of-array

def chk(m, nums):
    quota = 0
    for n in nums:
        if n < m: quota += m - n
        else:
            if quota < n - m: return False
            quota -= (n - m)
    return True

class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        l, r = 0, max(nums)
        while l <= r: 
            m = (l + r) // 2
            if chk(m, nums):
                ans, r = m, m - 1
            else: l = m + 1
        return ans