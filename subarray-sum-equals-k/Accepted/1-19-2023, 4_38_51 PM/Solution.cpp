// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, tot = 0;
        map<int, int> m; m[0]++;
        for(auto n: nums){
            tot += n;
            if(m.find(tot - k) != m.end()) ans += m[tot - k];
            m[tot]++;
        }
        return ans;
    }
};