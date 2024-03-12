// https://leetcode.com/problems/distribute-money-to-maximum-children

class Solution {
public:
    int distMoney(int n, int children) {
        if(n< children) return -1;
        if((n-4) % 8 == 0) return n / 8 - 1;
        return n / 8;
    }
};