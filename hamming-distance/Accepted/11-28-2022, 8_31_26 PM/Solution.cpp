// https://leetcode.com/problems/hamming-distance

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<31>ans(x^y);
        return ans.count();
    }
};