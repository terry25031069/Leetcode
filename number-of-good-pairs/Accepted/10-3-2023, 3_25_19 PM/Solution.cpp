// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[101] = {};
        for(auto i: nums) cnt[i]++;
        int ans = 0;
        for(auto i: cnt) if(i > 1) ans += (i - 1) * i / 2;
        return ans; 
    }
};