// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int loca = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] >= nums[i + 1]){
                loca = i;
                break;
            }
        }
        if(loca == -1) return true;
        cout << loca << endl;
        nums.erase(nums.begin() + loca);
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] >= nums[i + 1]){
                return false;
            }
        }
        return true;
    }
};