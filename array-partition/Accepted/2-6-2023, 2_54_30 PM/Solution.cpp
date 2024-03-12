// https://leetcode.com/problems/array-partition

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += (!(i & 1)) * nums[i];
        }
        return ans;
    }
};