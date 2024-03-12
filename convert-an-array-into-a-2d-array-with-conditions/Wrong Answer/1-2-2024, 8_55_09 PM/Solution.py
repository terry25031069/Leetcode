// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        ans, tmp = [], []
        for n in nums:
            if n in tmp:
                ans.append(tmp)
                tmp = [n]
            else:
                tmp.append(n)
        ans.append(tmp)
        return ans