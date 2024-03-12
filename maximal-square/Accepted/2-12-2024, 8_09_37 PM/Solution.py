// https://leetcode.com/problems/maximal-square

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ans = 1
        m, n = len(matrix), len(matrix[0])

        def checkMatrixWithLengthN(ans :int) -> bool:
            count = 0
            for p in range(m - ans + 1):
                for q in range(n - ans + 1):
                    for j in range(p, p + ans):
                        for k in range(q, q + ans):
                            if matrix[j][k] == '1':
                                count += 1
                            else: 
                                break
                    if count == ans ** 2:
                        return True
                    count = 0
            return False
            
        while 1:
            chk = checkMatrixWithLengthN(ans)
            if chk: 
                ans += 1
            else: break
        ans -= 1
        return ans ** 2