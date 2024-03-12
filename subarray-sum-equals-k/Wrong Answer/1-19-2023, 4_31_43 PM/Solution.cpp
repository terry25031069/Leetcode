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
            if(m.find(key + k) != m.end()){
                if(k) ans += v * m[key + k];
                else ans += v * (v - 1) / 2;
            }
        }
        return ans;
    }
};