// https://leetcode.com/problems/integer-replacement

class Solution {
public:
    int integerReplacement(long long n) {
        if(n < 4) return n - 1;
        if(n % 4 == 3) return integerReplacement(n + 1) + 1;
        else if(n & 1) return integerReplacement(n - 1) + 1;
        return integerReplacement(n >> 1) + 1;
    }
};