// https://leetcode.com/problems/check-if-point-is-reachable

class Solution {
public:
    bool isReachable(int X, int Y) {
        return !(gcd(X, Y) & (gcd(X, Y) - 1));
    }
};