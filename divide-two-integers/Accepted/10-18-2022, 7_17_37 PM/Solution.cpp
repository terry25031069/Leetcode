// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long tmp = (long long)dividend / (long long)divisor;
        if(tmp > INT_MAX) return INT_MAX;
        else if(tmp < INT_MIN) return INT_MIN;
        else return int(tmp);
    }
};