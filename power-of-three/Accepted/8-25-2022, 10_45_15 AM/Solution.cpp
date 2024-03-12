// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int value) {
        return value > 0 && 1162261467 % value == 0;
    }
};