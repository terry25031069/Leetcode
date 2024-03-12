// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma, cnt;
        ma = cnt = 0;
        for(auto i: nums){
            cnt = max(0, cnt + i);
            ma = max(ma, cnt);
        }
        return ma;
    }
};