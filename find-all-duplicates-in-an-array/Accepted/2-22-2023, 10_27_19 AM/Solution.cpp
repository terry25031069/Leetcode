// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> cnt(nums.size() + 1, 0);
        vector<int> ans;
        for(auto i: nums){
            cnt[i]++;
            if(cnt[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};