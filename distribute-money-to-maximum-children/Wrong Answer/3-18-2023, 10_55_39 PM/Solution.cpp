// https://leetcode.com/problems/distribute-money-to-maximum-children

class Solution {
public:
    int distMoney(int n, int children) {
        if(n < children) return -1;
        if(n >= 8 * children) return children;
        int ans = 0;
        n -= children;
        while(n > 7) n -= 7, ans++;
        if(n == 3 && ans && children - ans == 1) ans--;
        return ans;
    }
};