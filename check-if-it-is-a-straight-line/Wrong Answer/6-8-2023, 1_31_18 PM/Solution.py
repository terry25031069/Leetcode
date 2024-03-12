// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        l = sorted(coordinates)
        if len(l) == 2: return True
        l = [(l[i][0] - l[i-1][0], l[i][1] - l[i-1][1]) for i in range(1, len(l))]
        return len(set(l)) == 1