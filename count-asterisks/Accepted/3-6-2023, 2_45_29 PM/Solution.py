// https://leetcode.com/problems/count-asterisks

class Solution:
    def countAsterisks(self, s: str) -> int:
        l = s.split('|')
        ans = 0
        for i in range(len(l)):
            if i % 2 == 0: ans += l[i].count('*')
        return ans