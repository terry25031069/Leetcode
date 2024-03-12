// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        int64_t ans = int64_t(n) * 2, x = floor(sqrt(ans));
        if(x * x + x > ans) return x - 1;
        return x;
    }
};