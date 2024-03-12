// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ansset;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        do{
            ansset.emplace(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        for(auto i: ansset){
            ans.emplace_back(i);
        }
        return ans;
    }
};