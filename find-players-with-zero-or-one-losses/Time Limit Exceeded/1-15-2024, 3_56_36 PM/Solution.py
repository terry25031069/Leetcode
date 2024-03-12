// https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        li = [ele for sl in matches for ele in sl]
        loscnt = [0] * (max(li) + 1)
        for [w, l] in matches:
            loscnt[l] += 1
        los = [[], []]
        for i in range(1, len(loscnt)):
            if i in li and loscnt[i] < 2: 
                los[loscnt[i]].append(i)
        return los
        
            