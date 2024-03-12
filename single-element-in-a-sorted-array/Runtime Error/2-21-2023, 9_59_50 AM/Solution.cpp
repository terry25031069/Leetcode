// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() / 2, m;
        while(l <= r){
            m = (r + l) / 2;
            if(nums[2 * m] != nums[2 * m + 1]) r = m - 1;
            else l = m + 1;
        }
        return nums[2*m];
    }
};