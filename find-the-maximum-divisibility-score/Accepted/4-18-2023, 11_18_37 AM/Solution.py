// https://leetcode.com/problems/find-the-maximum-divisibility-score

class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        t = [sum([1 if n % d == 0 else 0 for n in nums]) for d in divisors]
        ans = int(1e9)
        m = max(t)
        for i in range(len(divisors)):
            if t[i] == m: ans = min(divisors[i], ans)
        return ans
        