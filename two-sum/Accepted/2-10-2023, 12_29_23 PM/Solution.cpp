// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size() - 1; i++){
            int tmp = target - nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                if(tmp == nums[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};