// https://leetcode.com/problems/smallest-range-i

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums.back() - nums.front() - 2 * k < 0? 0: nums.back() - nums.front() - 2 * k;
    }
};