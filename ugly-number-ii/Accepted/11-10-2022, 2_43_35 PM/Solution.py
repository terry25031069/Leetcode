// https://leetcode.com/problems/ugly-number-ii

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ans = []
        for i in range(0, 31):
            for j in range(0, 20):
                for k in range(0, 14):
                    tmp = 2 ** i * 3 ** j * 5 ** k
                    ans.append(tmp)
        ans = sorted(ans)
        return ans[n-1];
