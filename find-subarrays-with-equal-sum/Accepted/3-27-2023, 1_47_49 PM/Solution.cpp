// https://leetcode.com/problems/find-subarrays-with-equal-sum

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if(nums.size() == 2) return false;
        map<int, int> m;
        for(int i = 0; i < nums.size() - 1; i++){
            if(m[nums[i+1] + nums[i]]) return true;
            m[nums[i+1] + nums[i]] = 1; 
        }
        return false;
    }
};