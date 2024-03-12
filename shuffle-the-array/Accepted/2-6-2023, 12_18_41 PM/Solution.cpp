// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr0; arr0.assign(nums.begin(), nums.begin() + n);
        vector<int> arr1; arr1.assign(nums.begin() + n, nums.end());
        vector<int> ans;
        for(int i = 0; i < arr0.size(); i++){
            ans.push_back(arr0[i]);
            ans.push_back(arr1[i]);
        }
        return ans;
    }
};