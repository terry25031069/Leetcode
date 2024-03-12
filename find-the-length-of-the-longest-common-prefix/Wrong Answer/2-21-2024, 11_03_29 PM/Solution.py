// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        def prefixCount(s1, s2):
            ans = 0
            for i in range(min(len(s1), len(s2))):
                if s1[i] == s2[i]: ans += 1
                else: break
            return ans
        ans = 0
        arr1 = list(map(str, arr1))
        arr2 = list(map(str, arr2))
        i, j, n, m = 0, 0, len(arr1), len(arr2)
        while i < n and j < m:
            ans = prefixCount(arr1[i], arr2[j])
            if arr1[i] == arr2[j]: 
                i += 1
                j += 1
            elif arr1[i] > arr2[j]:
                j += 1
            else: 
                i += 1
        return ans
