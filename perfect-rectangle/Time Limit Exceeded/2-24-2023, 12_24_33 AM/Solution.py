// https://leetcode.com/problems/perfect-rectangle

def area(l):
    return (l[2] - l[0]) * (l[3] - l[1])

def coarea(l1, l2):
    leng, wid = 0, 0
    if not(l1[2] <= l2[0] or l2[2] <= l1[0]): 
        s = sorted([l1[0], l1[2], l2[0], l2[2]])
        leng = s[2] - s[1]
    if not (l1[3] <= l2[1] or l2[3] <= l1[1]):
        s = [l1[1], l1[3], l2[1], l2[3]]
        wid = s[2] - s[1]
    return leng and wid

class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        summ = 0
        for i in range(len(rectangles) - 1):
            for j in range(i + 1, len(rectangles)):
                minx = min(rectangles[i][0], rectangles[j][0])
                miny = min(rectangles[i][1], rectangles[j][1])
                maxx = max(rectangles[i][2], rectangles[j][2])
                maxy = max(rectangles[i][3], rectangles[j][3])
                if coarea(rectangles[i], rectangles[j]):
                    return False

        minx, miny = 1e6, 1e6
        maxx, maxy = -1e6, -1e6
        for i in range(len(rectangles)):
            summ += area(rectangles[i])
            minx = min(rectangles[i][0], minx)
            miny = min(rectangles[i][1], miny)
            maxx = max(rectangles[i][2], maxx)
            maxy = max(rectangles[i][3], maxy)
        area_max = area([minx, miny, maxx, maxy])
        return area_max == summ