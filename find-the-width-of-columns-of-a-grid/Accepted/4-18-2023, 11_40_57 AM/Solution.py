// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid

class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        ans = []
        for i in range(len(grid[0])):
            ans.append(max([len(str(grid[j][i])) for j in range(len(grid))]))
        return ans