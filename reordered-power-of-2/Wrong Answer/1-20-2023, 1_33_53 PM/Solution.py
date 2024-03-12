// https://leetcode.com/problems/reordered-power-of-2

def Cnt(n):
        cnt = Counter(str(n))
        return tuple(cnt)
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        m = {}
        for i in range(0, 31):
            m[Cnt(2 ** i)] = 1
        return (Cnt(n) in m)