// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>ans;
        for(auto i: nums){
            if(i) ans.push_back(i);
        }
        ans.resize(nums.size());
        nums = ans;
    }
};