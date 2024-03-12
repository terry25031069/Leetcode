// https://leetcode.com/problems/unique-number-of-occurrences

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        cnt = [0] * 2001
        s = set()
        for i in arr: 
            cnt[i + 1000] += 1
            s.add(i + 1000)
        ans = [cnt[i] for i in range(len(cnt)) if i in s]
        return len(set(ans)) == len(ans) 
