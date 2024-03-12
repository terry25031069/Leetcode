// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution:
    def average(self, salary: List[int]) -> float:
        s = sorted(salary)
        s = s[1:-1]
        return sum(s)/len(s)
