// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution:
    def nextGreatestLetter(self, letter: List[str], target: str) -> str:
        letter.append(target)
        letter = sorted(list(set(letter)))
        tmp = letter.index(target)
        if tmp == len(letter) - 1: return letter[0]
        return letter[tmp + 1]

