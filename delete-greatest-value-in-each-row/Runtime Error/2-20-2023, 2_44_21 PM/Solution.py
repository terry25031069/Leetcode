// https://leetcode.com/problems/delete-greatest-value-in-each-row

class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        for i in grid:
            grid[i] = sorted(grid[i])
        n = range(len(grid))
        m = [max([grid[i][j] for i in n]) for j in n]
        return sum(m)