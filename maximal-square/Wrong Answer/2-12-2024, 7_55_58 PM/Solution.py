// https://leetcode.com/problems/maximal-square

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ans = 1
        m, n = len(matrix), len(matrix[0])
        exist = 0
        while 1:
            count = 0
            #print('i = ', i)
            for p in range(m - ans + 1):
                for q in range(n - ans + 1):
                    for j in range(p, p + ans):
                        for k in range(q, q + ans):
                            if matrix[j][k] == '1':
                                count += 1
                    if count == ans ** 2:
                        ans += 1
                        exist = 1
                        break
                if exist: 
                    break
            if exist == 0: break
            exist = 0
            count = 0
        ans -= 1
        return ans ** 2