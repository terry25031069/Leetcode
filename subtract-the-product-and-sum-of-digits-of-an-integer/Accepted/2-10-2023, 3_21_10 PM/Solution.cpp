// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int a = 1, b = 0;
        while(n) a *= (n % 10), b += (n % 10), n /= 10;
        return a - b;
    }
};