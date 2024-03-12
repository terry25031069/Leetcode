// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int l = i + 1, r = nums.size() - 1;
            int lo = -1e6, ro = -1e6;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0 || lo == nums[l]) l++;
                else if(nums[i] + nums[l] + nums[r] > 0 || ro == nums[r]) r--;
                else{
                    lo = nums[l], ro = nums[r];
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                }
            }
        }
        return ans;
    }
};