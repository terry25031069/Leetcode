// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k

class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        l, r = 0, 1
        ans = 0
        for i in s:
            if int(i) > k: return false
        while r < len(s):
            while int(s[l: r + 1]) < k: 
                r += 1
            print(s[l: r])
            l = r
            r = l + 1
            ans += 1
        if int(s[l: r + 1]) < k: ans += 1
        return ans
        