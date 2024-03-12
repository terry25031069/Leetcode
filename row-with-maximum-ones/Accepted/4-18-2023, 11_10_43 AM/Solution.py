// https://leetcode.com/problems/row-with-maximum-ones

class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        ans = 0
        for i in range(len(mat)):
            if sum(mat[i]) > sum(mat[ans]): ans = i
        return [ans, sum(mat[ans])]