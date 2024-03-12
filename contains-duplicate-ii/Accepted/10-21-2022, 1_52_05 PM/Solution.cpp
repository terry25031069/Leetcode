// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int>coord;
        for(int i = 0; i < nums.size(); i++){
            if(coord[nums[i]] == 0) coord[nums[i]] = i + 1;
            else{
                if(i - coord[nums[i]] + 1 <= k) return true;
                else coord[nums[i]] = i + 1;
            }
        }
        return false;
    }
};