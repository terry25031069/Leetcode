// https://leetcode.com/problems/unique-morse-code-words

class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        moose = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        d = {}
        for i in words:
            tmp = ""
            for j in i:
                tmp += moose[ord(j) - 97]
            d[tmp] = d.setdefault(tmp, 1)
        return len(d)