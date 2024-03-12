// https://leetcode.com/problems/first-completely-painted-row-or-column

class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        rows, cols = [len(mat[0])] * len(mat), [len(mat)] * len(mat[0])
        d = {}
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                d[mat[i][j]] = (i, j)
        for idx in range(len(arr)):
            i, j = d[arr[idx]]
            print(i, j, rows[i], cols[j])
            rows[i] -= 1
            cols[j] -= 1
            if rows[i] == 0 or cols[j] == 0:
                return idx
        return -1
        
