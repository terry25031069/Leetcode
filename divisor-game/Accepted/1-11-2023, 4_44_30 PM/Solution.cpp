// https://leetcode.com/problems/divisor-game

class Solution {
public:
    bool divisorGame(int n) {
        bool ans[n + 1];
        memset(ans, 0, sizeof(ans));
        ans[0] = 1, ans[1] = 0;
        for(int i = 1; i <= n; i++){
            if(i + 1 <= n)ans[i + 1] |= (1 - ans[i]);
            if(i * 2 <= n)ans[i * 2] |= (1 - ans[i]);
        }
        return ans[n];
    }
};