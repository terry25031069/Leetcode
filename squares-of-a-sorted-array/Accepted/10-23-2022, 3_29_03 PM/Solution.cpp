// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &i: nums){
            i *= i;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};