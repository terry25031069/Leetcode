// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        nums.push_back(1e6);
        int ans = 0, diff = nums[1] - nums[0], cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == diff) cnt++;
            else{
                //cout << cnt << endl;
                if(cnt > 2) ans += (cnt-1)*(cnt)/2;
                cnt = 1, diff = nums[i]-nums[i-1];
            }
        }
        return ans;
    }
};