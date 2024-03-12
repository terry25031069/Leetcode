// https://leetcode.com/problems/perfect-rectangle

def area(l):
    return (l[2] - l[0]) * (l[3] - l[1])

class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        summ = 0
        for i in range(len(rectangles) - 1):
            for j in range(i + 1, len(rectangles)):
                minx = min(rectangles[i][0], rectangles[j][0])
                miny = min(rectangles[i][1], rectangles[j][1])
                maxx = max(rectangles[i][2], rectangles[j][2])
                maxy = max(rectangles[i][3], rectangles[j][3])
                if area(rectangles[i]) + area(rectangles[j]) > area([minx, miny, maxx, maxy]):
                    return False

        minx = rectangles[0][0]
        miny = rectangles[0][1]
        maxx = rectangles[0][2]
        maxy = rectangles[0][3]
        for i in range(len(rectangles)):
            summ += area(rectangles[i])
            if minx > rectangles[i][0]:
                minx = rectangles[i][0]
            if miny > rectangles[i][1]:
                miny = rectangles[i][1]
            if maxx < rectangles[i][2]:
                maxx = rectangles[i][2]
            if maxy < rectangles[i][3]:
                maxy = rectangles[i][3]
        area_max = area([minx, miny, maxx, maxy])
        return area_max == summ