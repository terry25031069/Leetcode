// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(auto i: nums) cout << i << ' '; cout << endl;
        int li, lj, ll, lr;
        li = -2e9;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 3; i++){
            if(li == nums[i]) continue; li = nums[i];
            lj = -2e9;
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(lj == nums[j]) continue; lj = nums[j];
                int l = j + 1, r = nums.size() - 1;
                ll = lr = -2e9;
                while(l < r){
                    int tot = nums[i] + nums[j] + nums[l] + nums[r];
                    if(tot > target || lr == nums[r]) r--;
                    else if(tot < target || ll == nums[l]) l++;
                    else{
                        ll = nums[l], lr = nums[r];
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                    }
                }
            }
        }
        return ans;
    }
};