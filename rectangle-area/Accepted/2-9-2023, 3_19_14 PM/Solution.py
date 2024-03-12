// https://leetcode.com/problems/rectangle-area

class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        leng, wid = 0, 0
        if not(ax2 <= bx1 or bx2 <= ax1): 
            tmp = sorted([ax1, bx1, ax2, bx2])
            leng = tmp[2] - tmp[1]
        if not (ay2 <= by1 or by2 <= ay1):
            tmp = sorted([ay1, ay2, by1, by2])
            wid = tmp[2] - tmp[1]
        return (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1) - leng * wid