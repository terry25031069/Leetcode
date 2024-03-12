// https://leetcode.com/problems/contains-duplicate

class Solution:
    def containsDuplicate(self, num: List[int]) -> bool:
        num = sorted(num)
        for i in range(len(num) - 1):
            if num[i] == num[i + 1]: return True
        return False