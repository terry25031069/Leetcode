// https://leetcode.com/problems/sequential-digits

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        s = "123456789"
        l = []
        for i in range(len(s)-1):
            for j in range(i + 1, len(s)):
                tmp = s[i:j+1]
                l.append(tmp)
        l = sorted(list(map(int, l)))
        return [i for i in l if low <= i <= high]