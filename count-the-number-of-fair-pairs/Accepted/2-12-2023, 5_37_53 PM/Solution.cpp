// https://leetcode.com/problems/count-the-number-of-fair-pairs

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int low = lower - nums[i], high = upper - nums[i];
            vector<int>::iterator l = lower_bound(nums.begin(), nums.end(), low);
            vector<int>::iterator r = upper_bound(nums.begin(), nums.end(), high); 
            int rr = r - nums.begin() - 1, ll = l - nums.begin();
            if(rr - max(i + 1, ll) < 0) continue;
            ans += rr - max(i + 1, ll) + 1;
        }
        return ans;
    }
};