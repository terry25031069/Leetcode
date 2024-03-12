// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        n = len(A)
        As, Bs = {}, {}
        for i in range(n):
            As[A[i]] = As.setdefault(A[i], 0) + 1
            Bs[B[i]] = Bs.setdefault(B[i], 0) + 1
            tmp = sum([min(Bs[i], As[i]) for i in As.keys() if i in Bs])
            ans.append(tmp)
        return ans
