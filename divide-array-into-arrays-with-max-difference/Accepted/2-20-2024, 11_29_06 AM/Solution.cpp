// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{{}};
        for(int i = 0; i < nums.size(); i++){
            ans.back().push_back(nums[i]);
            if(i % 3 == 2){
                auto v = ans.back(); int mi = v[0], ma = v[2];
                if(ma - mi > k) return {};
                ans.push_back({});
            }
        }
        ans.pop_back();
        return ans;
    }
};