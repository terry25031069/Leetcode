// https://leetcode.com/problems/distribute-money-to-maximum-children

class Solution {
public:
    int distMoney(int n, int children) {
        if(n < children) return -1;
        if(n >= 8 * children) return children;
        n -= children;
        if(n % 7 == 3) return max(n / 7 - 1, 0);
        return max(n / 7, 0);
    }
};