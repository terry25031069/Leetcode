// https://leetcode.com/problems/keyboard-row

class Solution(object):
    def findWords(self, words):
        row = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        ans = []
        for s in words:
            if all([0 if ch in row[0] else (1 if ch in row[1] else 2) for ch in s]):
                ans.append(s)
        return ans