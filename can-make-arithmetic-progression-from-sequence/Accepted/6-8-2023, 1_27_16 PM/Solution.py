// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        l = sorted(arr)
        l = [l[i] - l[i-1] for i in range(1, len(l))]
        return len(set(l)) == 1