// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), m;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return (nums[m] == target? m : -1);
    }
};