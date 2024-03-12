// https://leetcode.com/problems/delete-greatest-value-in-each-row

class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        n = range(len(grid))
        for i in n:
            grid[i] = sorted(grid[i])
        m = [max([grid[i][j] for i in n]) for j in range(len(grid[0]))]
        print(m)
        return sum(m)