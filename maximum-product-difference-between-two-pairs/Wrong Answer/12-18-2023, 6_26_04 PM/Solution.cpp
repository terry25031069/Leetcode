// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        return nums[n-1] * nums[n-2] - nums[0] * nums[1];
    }
};