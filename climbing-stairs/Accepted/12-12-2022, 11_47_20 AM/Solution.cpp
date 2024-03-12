// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
       int ans[100] = {1, 1, 2};
       for(int i = 3; i < 46; i++){
           ans[i] = ans[i-1] + ans[i-2];
       } 
       return ans[n];
    }
};