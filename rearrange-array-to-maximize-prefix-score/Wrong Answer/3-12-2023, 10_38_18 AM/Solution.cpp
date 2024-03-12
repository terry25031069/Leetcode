// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i: nums){
            if(i > 0) ans += i;
            else break;
        }
        return ans;
    }
};