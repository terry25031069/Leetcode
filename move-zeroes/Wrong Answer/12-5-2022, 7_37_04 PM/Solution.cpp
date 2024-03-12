// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    static bool cmp(int a, int b){
        if(a == 0) return 0;
        if(b == 0) return 1;
        return 1;
    }
    void moveZeroes(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
    }
};