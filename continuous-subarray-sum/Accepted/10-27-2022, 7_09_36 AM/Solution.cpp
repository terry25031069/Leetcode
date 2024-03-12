// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int>mod;
        int tot = 0;
        for(int i = 0; i < nums.size(); i++){
            tot = (tot + nums[i]) % k;
            if(tot && !mod[tot]) mod[tot] = i + 1;
            if(i > mod[tot]) return true;
        }
        return false;
    }
};