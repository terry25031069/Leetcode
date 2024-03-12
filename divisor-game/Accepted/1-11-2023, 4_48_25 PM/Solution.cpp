// https://leetcode.com/problems/divisor-game

class Solution {
public:
    bool divisorGame(int n) {
        if(n == 1) return false;
        bool ans = false;
        if(n & 1 == 0) ans |= (!divisorGame(n / 2));
        if(ans) return ans;
        ans |= (!divisorGame(n - 1));
        return ans;
    }
};