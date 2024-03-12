// https://leetcode.com/problems/build-array-from-permutation

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans;
        for(auto i: nums){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};