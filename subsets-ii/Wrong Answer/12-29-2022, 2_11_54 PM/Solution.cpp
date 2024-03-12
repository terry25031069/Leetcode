// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i = 0; i < (1 << nums.size()); i++){
            bitset<10> tmp(i);
            vector<int> unit;
            for(int j = 0; j < nums.size(); j++){
                if(tmp[j]) unit.push_back(nums[j]);
            }
            if(s.find(unit) == s.end())ans.push_back(unit), s.insert(unit);
        }
        return ans;
    }
};