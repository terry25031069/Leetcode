// https://leetcode.com/problems/power-of-four

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n % 4 == 0 && n^(n-1) == 0 || n == 1);
    }
};