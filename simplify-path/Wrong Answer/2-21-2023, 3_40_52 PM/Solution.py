// https://leetcode.com/problems/simplify-path

class Solution:
    def simplifyPath(self, path: str) -> str:
        l = path.replace('//', '/').split('/')
        print(l)
        tmp = []
        for i in l:
            if len(i) == 0: continue
            if i == '..':
                if len(tmp) > 0:
                    tmp.pop()
            else:
                tmp.append(i)
        ans = "/" + "/".join(tmp)
        return ans
