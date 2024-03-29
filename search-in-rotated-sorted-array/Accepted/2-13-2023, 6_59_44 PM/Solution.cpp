// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int bi_search(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(nums[m] == target) return m;
            else if(nums[m]>=nums[l]){
                if(nums[m] >= target && nums[l]<= target) r = m - 1;
                else l = m + 1;
            }
            else{
                if(nums[m] <= target && nums[r]>= target) l = m + 1;
                else r = m - 1;

            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bi_search(nums, target);
    }
};