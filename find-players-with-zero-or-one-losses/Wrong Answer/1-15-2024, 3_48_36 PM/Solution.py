// https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        ma = max([max(sl) for sl in matches])
        loscnt = [0] * (ma + 1)
        for [w, l] in matches:
            loscnt[l] += 1
        los = [[], []]
        for i in range(1, len(loscnt)):
            if loscnt[i] < 2:
                los[loscnt[i]].append(i)
        return los
        
            