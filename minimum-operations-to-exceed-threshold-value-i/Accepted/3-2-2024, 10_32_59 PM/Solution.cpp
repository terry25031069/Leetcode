// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int i;
        sort(nums.begin(), nums.end());
        for(i= 0; i < nums.size(); i++){
            if(nums[i] >= k) break;
        }
        return i;
    }
};