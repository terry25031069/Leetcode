// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        colors += 'A'
        neededTime.append(0)
        times = 0
        colorintime = []
        currentcolor = colors[0]
        for i in range(len(colors)):
            if colors[i] != currentcolor:
                times += sum(colorintime) - max(colorintime)
                colorintime.clear()
                currentcolor = colors[i]
            colorintime.append(neededTime[i])
        return times