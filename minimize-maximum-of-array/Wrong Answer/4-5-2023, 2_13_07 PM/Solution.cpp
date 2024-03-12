// https://leetcode.com/problems/minimize-maximum-of-array

class Solution {
public:
    int chk(int m, vector<int>& nums){
        //cout << m << endl;
        for(int i = 1; i < nums.size(); i++){
            if(m < nums[i-1]) return false;
            nums[i] -= (m - nums[i-1]);
            nums[i-1] = m;
        }
        //for(auto i: nums) cout << i << ' '; cout << endl;
        return nums.back() <= m;
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