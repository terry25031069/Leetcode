// https://leetcode.com/problems/longest-common-prefix

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        l = min(strs, key = len)
        s = ""
        for i in range(len(l)):
            tmp = l[:i + 1]
            flag = 0
            for ii in strs:
                if ii[:i + 1] != tmp:
                    flag = 1
                    break
            if flag == 0: s = tmp
        return s