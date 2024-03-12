// https://leetcode.com/problems/reordered-power-of-2

def Cnt(n):
        cnt = Counter(str(n))
        return cnt
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        for i in range(0, 31):
            if Cnt(str(n)) == Cnt(str(1 << i)): return True
        return False