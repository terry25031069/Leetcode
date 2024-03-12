// https://leetcode.com/problems/find-subarrays-with-equal-sum

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if(nums.size() == 2) return false;
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] != nums[i + 2]) return false;
        }
        return true;
    }
};