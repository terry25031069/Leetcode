// https://leetcode.com/problems/last-visited-integers

class Solution:
    def lastVisitedIntegers(self, nums: List[int]) -> List[int]:
        seen, ans = [], []
        k = 0
        for n in nums:
            if n > 0:
                seen = [n] + seen
                k = 0
            else:
                k += 1
                if k <= len(seen):
                    ans.append(seen[k-1])
                else:
                    ans.append(-1)
        return ans