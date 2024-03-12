// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:
    bool chk(int m, vector<int>& nums){
        int64_t quota = 0;
        for(int n: nums){
            if(n <= m) quota += m - n;
            else{
                if(quota < n - m) return false;
                quota -= (n - m);
            }
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end()), m, ans;
        while(l <= r){
            m = l + (r - l) / 2;
            if(chk(m, nums)){
                ans = m;
                r = m - 1;
            }else l = m + 1;
        }
        return ans;
    }
};