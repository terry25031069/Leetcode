// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        l = sorted(coordinates)
        if len(l) == 2: return True
        l = [(l[i][0] - l[i-1][0], l[i][1] - l[i-1][1]) for i in range(1, len(l))]
        if len(set(l)) == 1: return True
        x = [i[0] for i in l]
        y = [i[1] for i in l]
        if any(x) == 0 or any(y) == 0: return True
        return False