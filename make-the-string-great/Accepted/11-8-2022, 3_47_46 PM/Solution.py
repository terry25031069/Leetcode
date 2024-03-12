// https://leetcode.com/problems/make-the-string-great

class Solution:
    def makeGood(self, s: str) -> str:
        tmp = s
        while 1:
            tmp = s
            for i in range(len(tmp) - 1):
                if tmp[i].lower() == tmp[i + 1].lower() and tmp[i].islower() != tmp[i+1].islower():
                    tmp = tmp[:i] + tmp[i + 2:]
                    break
            if tmp == s: break 
            s = tmp
            print(tmp)
        return tmp