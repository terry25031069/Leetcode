// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        tmp = {}
        for i in tasks: tmp[i] = tmp.setdefault(i, 0) + 1
        ans = 0
        for k, v in tmp.items():
            if v < 2: return -1
            else: ans += (v + 2) // 3
        return ans