// https://leetcode.com/problems/frequency-tracker

class FrequencyTracker:
    def __init__(self):
        self.m = {}

    def add(self, number: int) -> None:
        self.m[number] = self.m.setdefault(number, 0) + 1

    def deleteOne(self, number: int) -> None:
        if number in self.m:
            self.m[number] -= 1
            if self.m[number] == 0: del self.m[number]

    def hasFrequency(self, frequency: int) -> bool:
        #print(self.m.values())
        return frequency in set(self.m.values())


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)