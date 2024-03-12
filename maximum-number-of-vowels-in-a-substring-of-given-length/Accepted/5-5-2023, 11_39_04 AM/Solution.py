// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        cur = sum([s[i] in "aeiou" for i in range(0, k)])
        ans = cur
        for i in range(k, len(s)):
            cur = cur - (s[i-k] in "aeiou") + (s[i] in "aeiou")
            ans = max(ans, cur)
        return ans