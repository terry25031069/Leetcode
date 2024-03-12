// https://leetcode.com/problems/keyboard-row

class Solution(object):
    def findWords(self, words):
        row = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        ans = []
        w = [s.lower() for s in words]
        for i in range(len(words)):
            if len(set([0 if ch in row[0] else (1 if ch in row[1] else 2) for ch in w[i]])) == 1:
                ans.append(words[i])
        return ans