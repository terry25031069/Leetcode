// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, tot = 0;
        map<int, int> m; m[0]++;
        for(auto n: nums){
            tot += n, m[tot]++;
        }
        for(auto [key, v]: m){
            //cout << key << ' ' << v << endl;
            if(m.find(key + k) != m.end()) ans += v * m[key + k];
        }
        if(k == 0) return m[0] * (m[0] - 1) / 2;
        return ans;
    }
};