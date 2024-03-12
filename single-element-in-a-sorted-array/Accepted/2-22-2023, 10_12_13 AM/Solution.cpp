// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() / 2, m, ans;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[2*m] != nums[2*m+1]){
                ans = m;
                r = m - 1;
            }else l = m + 1;
        }
        return nums[2*ans];
    }
};