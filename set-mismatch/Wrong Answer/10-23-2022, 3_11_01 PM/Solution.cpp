// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i + 1 != nums[i]){
                return vector<int>{nums[i], i + 1};
            }
        }
        return vector<int>{0, 0};
    }
};