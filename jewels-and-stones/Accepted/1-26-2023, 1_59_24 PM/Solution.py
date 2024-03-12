// https://leetcode.com/problems/jewels-and-stones

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        d = {}
        for i in jewels:
            d[i] = 1
        ans = 0
        for i in stones:
            if i in d: ans += 1
        return ans