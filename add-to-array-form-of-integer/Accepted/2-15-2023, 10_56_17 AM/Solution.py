// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        num = list(str(int("".join(list(map(str, num)))) + k))
        return list(map(int, num))
