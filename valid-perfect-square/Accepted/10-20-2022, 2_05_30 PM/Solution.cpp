// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        int x = int(sqrt(num));
        return x * x == num;
    }
};