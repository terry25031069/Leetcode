// https://leetcode.com/problems/distribute-money-to-maximum-children

class Solution {
public:
    int distMoney(int n, int children) {
        if(n < children) return -1;
        if(n >= 8 * children) return children;
        n -= children;
        int ans = n / 7, res = n % 7;
        if(!ans) return ans;
        if(res == 3 && children == 2) return ans - 1;
        return ans;
    }
};