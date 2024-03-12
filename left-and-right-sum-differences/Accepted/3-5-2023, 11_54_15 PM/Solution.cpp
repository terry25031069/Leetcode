// https://leetcode.com/problems/left-and-right-sum-differences

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> ans;
        int s = 0;
        for(int i: nums) s += i;
        for(int i: nums) ans.push_back(abs(s - i)), s -= 2*i;
        return ans;
    }
};