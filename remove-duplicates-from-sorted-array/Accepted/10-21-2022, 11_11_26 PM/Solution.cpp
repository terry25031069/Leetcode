// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                ans.push_back(nums[i]);
            }else{
                if(ans.back() == nums[i])continue;
                ans.push_back(nums[i]);
            }
        }
        nums = ans;
        return nums.size();
    }
};