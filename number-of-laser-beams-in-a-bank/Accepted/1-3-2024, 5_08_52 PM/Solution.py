// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans = 0
        l = [s.count('1') for s in bank if s.count('1')]
        for i in range(len(l) - 1):
            ans += l[i] * l[i+1]
        return ans
