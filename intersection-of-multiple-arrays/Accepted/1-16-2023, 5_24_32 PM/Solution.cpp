// https://leetcode.com/problems/intersection-of-multiple-arrays

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>tot(1001, 0);
        for(auto v: nums){
            for(auto i: v){
                tot[i]++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < tot.size(); i++){
            if(tot[i] == nums.size()) ans.push_back(i);
        }
        return ans;
    }
};