// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        n = (n + 1) * n / 2;
        for(int i: nums) n -= i;
        return n;
    }
};