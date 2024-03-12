// https://leetcode.com/problems/number-of-zero-filled-subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        nums.push_back(1);
        long long ans = 0, cnt = 0;
        for(auto i: nums){
            if(i) ans += cnt * (cnt + 1) / 2, cnt = 0;
            else cnt++;
        }
        return ans;
    }
};