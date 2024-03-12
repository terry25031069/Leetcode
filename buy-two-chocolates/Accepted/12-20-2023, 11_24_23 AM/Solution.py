// https://leetcode.com/problems/buy-two-chocolates

class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        ans = money - sum(sorted(prices)[:2])
        return ans if ans > -1 else money
        