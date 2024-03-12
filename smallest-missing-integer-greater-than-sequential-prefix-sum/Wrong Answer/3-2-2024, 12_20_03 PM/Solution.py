// https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum

class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        ans = nums[0]
        s = set()
        n = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == n + 1:
                n = n + 1
                ans += n
            s.add(nums[i])
        while ans in s: ans += 1
        return ans

            