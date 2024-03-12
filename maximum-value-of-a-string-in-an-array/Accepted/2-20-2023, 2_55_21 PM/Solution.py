// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array

class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        return max([(int(i) if i.isdigit() else len(i)) for i in strs])
