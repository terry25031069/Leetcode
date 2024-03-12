// https://leetcode.com/problems/apply-operations-to-an-array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                if(i < nums.size() -1 && nums[i] == nums[i+1]){
                    ans.push_back(nums[i] * 2);
                    i++;
                }else{
                    ans.push_back(nums[i]);
                }
            }
        }
        ans.resize(nums.size());
        return ans;
    }
};