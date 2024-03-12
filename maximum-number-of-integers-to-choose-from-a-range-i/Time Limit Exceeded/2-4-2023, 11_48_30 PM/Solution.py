// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i

class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        ans = 0
        for i in range(1, n + 1):
            if i not in banned and maxSum >= i:
                maxSum -= i
                ans += 1
            else:
                if maxSum < i: break
        return ans
        