// https://leetcode.com/problems/number-complement

class Solution:
    def findComplement(self, num: int) -> int:
        s = "{0:b}".format(num)
        print(s)
        ss = ""
        for i in range(len(s)):
            if s[i] == '0': ss += '1'
            else: ss += '0'
        return int(ss, 2)