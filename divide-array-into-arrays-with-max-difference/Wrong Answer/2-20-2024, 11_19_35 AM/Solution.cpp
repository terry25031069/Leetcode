// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i % 3 == 0) ans.push_back({});
            ans.back().push_back(nums[i]);
        }
        for(auto v: ans){
            int mi = v[0], ma = v[2];
            if(ma - mi != k) return {};
        }
        return ans;
    }
};