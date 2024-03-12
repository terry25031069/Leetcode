// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int>mod;
        int tot = 0;
        for(int i = 0; i < nums.size(); i++){
            tot = (tot + nums[i]) % k;
            cout << tot << " \n"[i == nums.size() -1];
            if(mod[tot] == 0 && tot) mod[tot] = i + 1;
            else return true;
        }
        return false;
    }
};