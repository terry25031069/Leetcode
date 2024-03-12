// https://leetcode.com/problems/apply-operations-to-make-string-empty

class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        m = {}
        for ch in s: m[ch] = m.setdefault(ch, 0) + 1
        ma = max(m.values())
        v = set([k for k, v in m.items() if v == ma])
        ans = ""
        for i in range(len(s) - 1, -1, -1):
            if s[i] in v:
                ans += s[i]
                v.remove(s[i])
            if len(v) == 0: break
        return ans[::-1]