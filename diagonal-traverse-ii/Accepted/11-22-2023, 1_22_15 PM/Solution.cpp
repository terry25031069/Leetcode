// https://leetcode.com/problems/diagonal-traverse-ii

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> tmp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                if(i + j >= tmp.size()) tmp.push_back({});
                tmp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto &v: tmp){
            reverse(v.begin(), v.end());
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};