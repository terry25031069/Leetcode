// https://leetcode.com/problems/count-total-number-of-colored-cells

class Solution {
public:
    long long coloredCells(int n) {
        return int64_t(n) * (n-1) * 2 + 1;
    }
};