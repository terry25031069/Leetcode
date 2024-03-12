// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int ans[100] = {};
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(n > 2 && ans[n]) return ans[n];
        ans[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3); 
        return ans[n];
    }
};