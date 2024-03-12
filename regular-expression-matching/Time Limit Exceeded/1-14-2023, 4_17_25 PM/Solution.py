// https://leetcode.com/problems/regular-expression-matching

import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return re.fullmatch(p, s) != None