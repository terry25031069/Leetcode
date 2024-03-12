// https://leetcode.com/problems/house-robber

class Solution { 
public:
    vector<int>ma;
    int rob(vector<int>& nums) {
        ma.push_back(nums[0]);
        ma.push_back(nums[1]);
        ma.push_back(nums[2] + nums[0]);
        for(int i = 3; i < nums.size(); i++){
            ma.push_back(nums[i] + max(ma[i-2], ma[i-3]));
        }
        int ans = -1;
        for(auto i: ma) ans = max(ans, i);
        return ans;
    }
};