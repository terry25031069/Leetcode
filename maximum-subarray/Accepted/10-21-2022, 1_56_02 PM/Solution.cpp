// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma, cnt;
        ma = cnt = -1e9;
        for(auto i: nums){
            cnt = max(i, cnt + i);
            ma = max(ma, cnt);
        }
        return ma;
    }
};