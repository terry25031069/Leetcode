// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        d = {}
        for n in nums:
            d[n] = d.setdefault(n, 0) + 1
        ans = []
        for i in range(max(d.values())):
            ans.append([])
        for k, v in d.items():
            for i in range(v):
                ans[i].append(k)
        return ans
            
