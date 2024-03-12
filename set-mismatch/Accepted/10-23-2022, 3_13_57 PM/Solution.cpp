// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int cnt[10001] = {};
       for(auto i: nums) cnt[i]++;
       vector<int>ans(2);
       for(int i = 1; i <= nums.size(); i++){
           if(cnt[i] == 2) ans[0] = i;
           if(cnt[i] == 0) ans[1] = i;
       }
       return ans;
    }
};