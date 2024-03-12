// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{nums};
        while(next_permutation(nums.begin(), nums.end())){
            ans.emplace_back(nums);
        }
        return ans;
    }
};