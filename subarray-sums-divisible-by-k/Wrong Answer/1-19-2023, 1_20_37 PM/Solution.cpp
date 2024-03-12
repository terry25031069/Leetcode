// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> m; m[0]++;
        int tot = 0, ans = 0;
        for(auto n: nums){
            tot = (tot + k + n) % k;
            m[tot]++;
        }
        for(auto [k, v]: m){
            ans += (v - 1) * v / 2; 
        }
        return ans;
    }
};