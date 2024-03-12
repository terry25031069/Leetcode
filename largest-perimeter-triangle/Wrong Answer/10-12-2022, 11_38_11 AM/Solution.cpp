// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = nums.size() - 1; i > 1; i--){
            if(nums[i-2] + nums[i-1] > nums[i]){
                ans = nums[i] + nums[i-1] + nums[i-2];
            }
        }
        return ans;
    }
};