// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int ans[100] = {0, 1, 1};
    int tribonacci(int n) {
        for(int i = 3; i <= n; i++) ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
        return ans[n];
    }
};