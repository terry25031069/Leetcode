// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s = s.lower()
        s1, s2 = s[:len(s) // 2], s[len(s) // 2:]
        ans = 0
        for i in s1:
            if i in ['a', 'e', 'i', 'o', 'u']: ans += 1
        for i in s2:
            if i in ['a', 'e', 'i', 'o', 'u']: ans -= 1
        return not ans