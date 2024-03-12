// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        return fib(n-1) + fib(n-2);
    }
};