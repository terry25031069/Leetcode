// https://leetcode.com/problems/find-xor-beauty-of-array

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};