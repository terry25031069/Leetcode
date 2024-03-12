// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ansr = 1e9, ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < target){
                    if(ansr > abs(sum - target)) ansr = abs(sum - target), ans = sum;
                    l++;
                }else if(sum > target){
                    if(ansr > abs(sum - target)) ansr = abs(sum - target), ans = sum;
                    r--;
                }else{
                    return target;
                }
            }
        }
        return ans;
    }
};