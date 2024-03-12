// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum

class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        count = 0
        for i in arr:
            if i == 0:
                count += 1
        if count == len(arr):
            return True

        total = sum(arr)
        if total % 3 != 0:
            return False
        acc = 0
        count = 0
        tmp = total
        for i in range(len(arr)):
            acc += arr[i]
            if acc == total / 3:
                tmp -= acc
                acc = 0
                count += 1
        
        return tmp == 0 and count >= 3