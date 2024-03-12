// https://leetcode.com/problems/minimum-index-sum-of-two-lists

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d = {}
        for i in range(len(list1)): 
            d.setdefault(list1[i], [10000, 10000])
            d[list1[i]][0] = i
        for i in range(len(list2)):
            d.setdefault(list2[i], [10000, 10000])
            d[list2[i]][1] = i
        ansi = min([v[0] + v[1] for k, v in d.items()])
        return [i for i in list1 if d[i][0] + d[i][1] == ansi]
        