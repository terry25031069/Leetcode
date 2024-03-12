// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int loc = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return loc;
    }
};