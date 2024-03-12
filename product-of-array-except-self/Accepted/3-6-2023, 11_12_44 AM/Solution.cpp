// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto backnums = nums;
        for(int i = 1; i < nums.size(); i++){
            nums[i] *= nums[i-1];
        }
        for(int i = nums.size() - 1; i > 0; i--){
            backnums[i-1] *= backnums[i];
        }
        // for(auto i: nums) cout << i << ' '; cout << endl;
        // for(auto i: backnums) cout << i << ' '; cout << endl;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) ans.push_back(backnums[1]);
            else if(i == nums.size() - 1) ans.push_back(nums[nums.size() - 2]);
            else ans.push_back(nums[i-1] * backnums[i+1]);
        }
        return ans;
    }
};