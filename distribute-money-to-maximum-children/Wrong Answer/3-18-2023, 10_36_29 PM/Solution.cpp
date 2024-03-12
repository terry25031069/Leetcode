// https://leetcode.com/problems/distribute-money-to-maximum-children

class Solution {
public:
    int distMoney(int n, int children) {
        if(n< children) return -1;
        if((n-4) % 8 == 0) return min(children, max(0, n / 8 - 1));
        return min(children, n / 8);
    }
};