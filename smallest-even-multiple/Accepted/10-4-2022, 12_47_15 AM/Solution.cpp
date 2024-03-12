// https://leetcode.com/problems/smallest-even-multiple

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n & 1) return n << 1;
        else return n;
    }
};