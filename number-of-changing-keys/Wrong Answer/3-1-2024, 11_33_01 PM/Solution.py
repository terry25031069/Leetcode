// https://leetcode.com/problems/number-of-changing-keys

class Solution:
    def countKeyChanges(self, s: str) -> int:
        return len(set(s.lower())) - 1