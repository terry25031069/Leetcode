// https://leetcode.com/problems/ant-on-the-boundary

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0, tot = 0;
        for(int i: nums){
            tot += i;
            if(tot == 0) ans += 1;
        }
        return ans;
    }
};