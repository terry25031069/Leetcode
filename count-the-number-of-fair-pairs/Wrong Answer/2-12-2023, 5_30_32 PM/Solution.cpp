// https://leetcode.com/problems/count-the-number-of-fair-pairs

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(auto i: nums) cout << i << ' '; cout << endl;
        for(int i = 0; i < nums.size(); i++){
            int low = lower - nums[i], high = upper - nums[i];
            vector<int>::iterator l = lower_bound(nums.begin(), nums.end(), low);
            vector<int>::iterator r = upper_bound(nums.begin(), nums.end(), high); 
            if(r - nums.begin() <= i) continue;
            //cout << l - nums.begin() << ' ' << r - nums.begin() - 1 << endl;
            ans += (r - l); 
        }
        return ans;
    }
};