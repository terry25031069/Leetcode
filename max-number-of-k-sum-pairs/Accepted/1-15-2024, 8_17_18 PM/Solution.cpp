// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> m;
        int ans = 0;
        for(int n: nums) m[n]++;
        for(auto [ke, va]: m){
            if(ke * 2 > k) break;
            if(ke * 2 != k) ans += min(m[ke],  m[k - ke]);
            else ans += m[ke] / 2;
        }
        return ans;
    }
};