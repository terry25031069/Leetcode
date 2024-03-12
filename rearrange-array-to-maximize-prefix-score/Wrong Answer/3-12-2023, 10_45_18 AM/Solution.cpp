// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int sum = 0, ans = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0] <= 0) return 0;
        for(int idx = 0; idx < nums.size(); idx++){
            int i = nums[idx];
            if(idx == 0 || sum > 0) ans++, sum += i;
            else break;
        }
        return ans;
    }
};