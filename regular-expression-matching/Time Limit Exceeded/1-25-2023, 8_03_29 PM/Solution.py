// https://leetcode.com/problems/regular-expression-matching

import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        pattern = re.compile("^" + p + "$")
        if pattern.search(s) is None:
            return False
        return True