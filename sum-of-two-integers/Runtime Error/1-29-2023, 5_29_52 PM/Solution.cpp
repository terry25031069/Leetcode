// https://leetcode.com/problems/sum-of-two-integers

class Solution {
public:
    int getSum(int a, int b) {
       return b == 0? a: getSum(a^b, (a&b) << 1); 
       //return b==0? a:getSum(a^b, (a&b)<<1); 
    }
};