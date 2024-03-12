// https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        g = math.gcd(len(str1), len(str2))
        for i in range(g, 0, -1):
            if g % i == 0:
                t = str1[:i]
                if t * (len(str1) // i) == str1 and t * (len(str2) // i) == str2:
                    return t
        return ""
            