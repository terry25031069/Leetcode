// https://leetcode.com/problems/compare-version-numbers

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1, l2 = list(map(int, version1.split('.'))), list(map(int, version2.split('.')))
        while l1[-1] == 0: l1 = l1[:-1]
        while l2[-1] == 0: l2 = l2[:-1]
        print(l1, l2)
        if l1 < l2: return -1
        elif l1 > l2: return 1
        else: return 0
        