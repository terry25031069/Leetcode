// https://leetcode.com/problems/number-of-distinct-averages

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<int> s;
        sort(nums.begin(), nums.end());
        for(int i = 0, j = nums.size() - 1; i < j; i++, j--){
            s.insert(nums[j] + nums[i]);
        }
        return s.size();
    }
};