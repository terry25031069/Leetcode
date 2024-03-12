// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0? !((1LL<<32) % int64_t(n)) : 0;
    }
};