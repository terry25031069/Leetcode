// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result

class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        ans = 0
        for i in range(len(number)):
            if number[i] == digit:
                tmp = int(number[:i]+number[i+1:])
                ans = max(ans, tmp)
        return ans
        